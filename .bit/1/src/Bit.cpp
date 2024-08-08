#include "Bit.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <sstream>
#include <iomanip>

Bit::Bit(std::string path_to_watch) : path_to_watch{path_to_watch}
{
    // Create .bit directory if it doesn't exist
    bit_dir = path_to_watch + "/.bit";
    if (!std::filesystem::exists(bit_dir))
    {
        std::filesystem::create_directory(bit_dir);
    }

    // Ensure version.txt exists
    std::string version_file = bit_dir + "/version.txt";
    if (!std::filesystem::exists(version_file))
    {
        std::ofstream(version_file);
    }

    std::string file_state_file = bit_dir + "/file_state.txt";
    if (!std::filesystem::exists(file_state_file))
    {
        // Perform initial commit
        commit("initial commit");
    }
    else
    {
        load_state();
    }
}

// Function checks for changes in the files, bool status is to obtain different behaviour with "commit" and "list changes" commands
bool Bit::check_files(bool status)
{
    bool changes = false;

    // Checking for erased files
    for (auto it = paths_.begin(); it != paths_.end();)
    {
        if (!std::filesystem::exists(it->first))
        {
            // Erased files are inserted into erased set
            erased.insert(it->first);
            changes = true;
            // incase of "commit" run path_ are updated, for "list changes" no updates in path_
            if (status)
                it = paths_.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Recursively iterate through the working directory and look for erased, modified and created files
    for (auto &file : std::filesystem::recursive_directory_iterator(path_to_watch))
    {
        // Ignore .bit directory
        if (file.path().string().rfind(bit_dir, 0) == 0)
            continue;

        auto current_file_last_write_time = file_check_method(file);
        if (!contains(file.path().string()))
        {
            // Incase of "commit" run path_ are updated, for "list changes" no updates in path_
            if (status)
            {
                paths_[file.path().string()] = current_file_last_write_time;
            }
            // Created files are inserted into created set
            created.insert(file.path().string());
            changes = true;
        }
        else
        {
            if (paths_[file.path().string()] != current_file_last_write_time)
            {
                // Incase of "commit" run path_ are updated, for "list changes" no updates in path_
                if (status)
                {
                    paths_[file.path().string()] = current_file_last_write_time;
                }
                // modified files are inserted into modified set
                modified.insert(file.path().string());
                changes = true;
            }
        }
    }

    if (changes)
    {
        for (const auto &i : erased)
            std::cout << "Erased: " << i << std::endl;

        for (const auto &i : modified)
            std::cout << "Modified: " << i << std::endl;

        for (const auto &i : created)
            std::cout << "Created: " << i << std::endl;
    }
    else
    { // Only for list changes behaviour
        if (!status)
            std::cout << "No Changes\n";
    }

    return changes;
}

bool Bit::contains(const std::string &key)
{
    return paths_.find(key) != paths_.end();
}

// Function to save the state of each file with their time into file_state.txt
void Bit::save_state()
{
    std::ofstream out(bit_dir + "/file_state.txt");
    if (out.is_open())
    {
        for (const auto &p : paths_)
        {
            // Time is written in epoch format
            out << p.first << ' ' << p.second.time_since_epoch().count() << '\n';
        }
    }
}

// Function to load the state of each files
void Bit::load_state()
{
    // To load the files from file_state.txt
    std::ifstream in(bit_dir + "/file_state.txt");
    if (in.is_open())
    {
        std::string path;
        std::filesystem::file_time_type::rep time;
        while (in >> path >> time)
        {
            // Converting the time back to file_time_type format from epoch
            paths_[path] = std::filesystem::file_time_type(std::chrono::duration_cast<std::filesystem::file_time_type::duration>(std::chrono::nanoseconds(time)));
        }
    }

    // To load the current version
    std::ifstream version_in(bit_dir + "/version.txt");
    if (version_in.is_open())
    {
        std::string line;
        while (std::getline(version_in, line))
        {
            std::istringstream iss(line);
            std::string key;
            if (std::getline(iss, key, ':'))
            {
                if (key == "Version")
                {
                    int version;
                    if (iss >> version)
                    {
                        version_number = version;
                    }
                    else
                    {
                        std::cerr << "Failed to parse version number.\n";
                    }
                }
            }
        }
    }
    std::cout << "Loaded version number: " << version_number << "\n";
}

// Function to copy changed files into each version directort with their relative path
void Bit::copy_files(const std::set<std::string> &files, const std::filesystem::path &version_dir)
{
    for (const auto &file : files)
    {
        std::filesystem::path source_path(file);
        auto relative_path = std::filesystem::relative(source_path, path_to_watch);
        auto destination_path = version_dir / relative_path;

        std::filesystem::create_directories(destination_path.parent_path());
        std::filesystem::copy(source_path, destination_path, std::filesystem::copy_options::overwrite_existing);
    }
}

void Bit::commit(const std::string &message)
{
    // Check for changes in the files
    bool changes = check_files();
    if (!changes)
    {
        std::cout << "No changes to commit.\n";
        return;
    }
    // Save the current state in the file_state.txt
    save_state();

    // Increment version number
    version_number++;

    // Get current time for timestamp
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time);

    // Format timestamp
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y%m%d_%H%M%S");
    std::string timestamp = oss.str();

    // Create version directory
    std::string version_dir = bit_dir + "/" + std::to_string(version_number);
    std::filesystem::create_directory(version_dir);

    // Write created, modified, and erased files to their respective files
    std::ofstream created_out(version_dir + "/created.txt");
    for (const auto &file : created)
    {
        created_out << file << '\n';
    }

    std::ofstream modified_out(version_dir + "/modified.txt");
    for (const auto &file : modified)
    {
        modified_out << file << '\n';
    }

    std::ofstream erased_out(version_dir + "/erased.txt");
    for (const auto &file : erased)
    {
        erased_out << file << '\n';
    }

    // Copy files to the version directory
    copy_files(created, version_dir);
    copy_files(modified, version_dir);

    // Clear the change sets
    created.clear();
    modified.clear();
    erased.clear();

    // Update the version file
    update_version_file(message, timestamp);

    std::cout << "Committed: " << message << "\n";
}

// Function to update the version file in the below format with each commit command
// Version: 1,Commit_message: Initial commit,Timestamp: 20240808_122600
void Bit::update_version_file(const std::string &message, const std::string &timestamp)
{
    std::ofstream version_out(bit_dir + "/version.txt", std::ios_base::app);
    if (version_out.is_open())
    {
        version_out << "Version: " << version_number << ',';
        version_out << "Commit_message: " << message << ',';
        version_out << "Timestamp: " << timestamp << '\n';
    }
    else
    {
        std::cerr << "Error: Could not open version file for appending.\n";
    }
}

// Function to list out all the versions
void Bit::list_versions()
{
    // Read from the text file throw error if not available
    // Print out all version available in the version.txt
    std::ifstream version_file(bit_dir + "/version.txt");
    if (!version_file.is_open())
    {
        std::cerr << "Failed to open version file.\n";
        return;
    }

    std::string line;
    while (std::getline(version_file, line))
    {
        std::cout << line << '\n';
    }
}
