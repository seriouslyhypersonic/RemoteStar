/*
 * CLASS SSH
 *
 * DESCRIPTION
 * SSH holds the data to establish the connection to the SSH server
 * running on the machine the STAR CCM+ job will be submitted to.
 *
 * NOTES
 * The access to the ssh machine must be done through SSH keys
 * so that no password is required during for ssh or scp commands.
 *
 * DEPENDENCIES
 * Required by star_client library.
 *
 *          Creator: Nuno Alves de Sousa
 *           E-mail: nunoalvesdesousa@me.com
 */
#ifndef SSH_H
#define SSH_H

#include <string>

class SSH {
private:
    std::string alias;         // Name to identify the machine running the ssh server
    std::string serverSSH;     // Address of the machine running the ssh server
    std::string userSSH;       // SSH username
public:
    // Getters
    std::string getAlias()  const;
    std::string getUser()   const;
    std::string getServer() const;

    // Class methods
    void loadSSH();
    void printConnectionData();
};
#endif //SSH_H