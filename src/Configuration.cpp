#include "../include/Configuration.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

Configuration::Configuration(const std::string &filepath) : filepath(filepath) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

void Configuration::parse(){

    std::string key;
    std::string value;

    ifs.open(filepath, std::ios::in);

    if(!ifs.is_open()){
        throw std::runtime_error("Configuration file with the provided path does not exist");
    }
    
    while(getline(ifs, key, '=')){

        key = key.substr(key.find_last_of('.') + 1) ;
        getline(ifs, value);

        if(static_cast<int>(std::count(key.begin(), key.end(), ' ')) == static_cast<int>(key.size())){
            throw std::runtime_error("Configuration Key must be provided");
        }
        else if(static_cast<int>(std::count(value.begin(), value.end(), ' ')) == static_cast<int>(value.size())){
            throw std::runtime_error("Configuration Value must be provided");
        }

        configMap[key] = value;
    }

    ifs.close();

    if(configMap["Type"] == ""){
        throw config::TypeNotProvidedException("Processor Type was not provided");
    }
}

Configuration::~Configuration() noexcept {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
    if(ifs.is_open()){
        ifs.close();
    }
}

std::ostream& operator<<(std::ostream &os, const Configuration &config){

    os << "{" << std::endl;

    for(const auto &kvPair : config.configMap){
        os << "     { " << kvPair.first << " : " << kvPair.second << " }" << std::endl; 
    }

    os << "}" << std::endl;

    return os;
}


