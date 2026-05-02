#include "../include/Configuration.hpp"
#include "../include/Processor.hpp"
#include "../include/ProcessorFactory.hpp"

#include <iostream>



int main(){

    Configuration config("./config/settings.txt");

    try{
        config.parse();
    }
    catch (const config::TypeNotProvidedException &e){
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
        std::clog << "[INFO] " << "Will use TextProcessor as Default Processor" << std::endl;
        config.getConfigMap()["Type"] = "Text";
    }
    catch (const std::runtime_error &e){
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
        return -1;
    }

    ProcessorFactory processorFactory;

    try{
        Processor &procssor = processorFactory.create(config);
        procssor.process();
    }
    catch(const config::InvalidProcessorTypeException& e){
        std::cerr << "[EXCEPTION] " << e.what() << std::endl;
        std::clog << "[INFO] " << "Will use TextProcessor as Default Processor" << std::endl;
        config.getConfigMap()["Type"] = "Text";
        Processor &procssor = processorFactory.create(config);
        procssor.process();
    }

    return 0;

}