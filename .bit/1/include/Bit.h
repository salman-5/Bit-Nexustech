#pragma once

#include <filesystem>
#include <unordered_map>
#include <string>
#include <set>

class Bit
{
public:
    // Path for working directory
    std::string path_to_watch;
    // Constructor
    Bit(std::string path_to_watch);

    // Function for checking the changes - used in "list changes" and "commit" commands
    // Use status = false for "list changes" behaviour
    bool check_files(bool status = true);
    // Function for commiting the changes
    void commit(const std::string &message);
    // Function to print out all available versions
    void list_versions();

    // TODO
    // To implement reset to certain version
    // There are two way to implement it either from version 1 to certain version or 
    // from current version to certain version
    // With current implementaion it will be easier to go from 1 to certain version

private:
    // To track the changes
    std::unordered_map<std::string, std::filesystem::file_time_type> paths_;
    // Store changes to the files in below sets
    std::set<std::string> erased;
    std::set<std::string> created;
    std::set<std::string> modified;

    std::string bit_dir;
    int version_number = 0;
    // By default, I have used time as measure of change to the file, we need to change this function compare the hash values of file for robust functioning
    std::filesystem::file_time_type file_check_method(const std::filesystem::directory_entry &file)
    {
        return std::filesystem::last_write_time(file);
    }

    // Copy changed files from one version to another
    void copy_files(const std::set<std::string> &files, const std::filesystem::path &version_dir);
    // To check if paths_ contains a certain key
    bool contains(const std::string &key);
    // Save the current state of each file to file_state.txt file
    void save_state();
    // Load state of each file from file_state.txt file
    void load_state();
    // To update the version.txt after each commit
    void update_version_file(const std::string &message, const std::string &timestamp);
};
