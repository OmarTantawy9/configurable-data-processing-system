#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>


class Configuration {
    std::map<std::string, std::string> configMap;
    std::ifstream ifs;
    std::string filepath;

public:

    Configuration(const std::string &filepath);
    void parse();

    inline std::map<std::string, std::string>& getConfigMap() {
        return configMap;
    }
    
    ~Configuration() noexcept;

    friend std::ostream& operator<<(std::ostream &os, const Configuration &config);

};


namespace config{
        class TypeNotProvidedException : public std::exception {
        const std::string message;
    public:
        TypeNotProvidedException(const std::string &message) : message(message) {}
        const char* what() const noexcept override{
            return message.c_str();
        }
    };

    class InvalidProcessorTypeException : public std::exception {
        const std::string message;
    public:
        InvalidProcessorTypeException(const std::string &message) : message(message) {}
        const char* what() const noexcept override{
            return message.c_str();
        }
    };
}



#endif //  CONFIGURATION_H