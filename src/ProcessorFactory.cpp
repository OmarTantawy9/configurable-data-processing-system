#include "../include/ProcessorFactory.hpp"

ProcessorFactory::ProcessorFactory() : processorPtr(nullptr) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

Processor &ProcessorFactory::create(Configuration &config){

    if(processorPtr){
        delete processorPtr;
    }

    const std::string &type = config.getConfigMap()["Type"];

    if (type == "Text"){
        processorPtr = new TextProcessor(config);
    }
    else if (type == "Numeric"){
        processorPtr = new NumericProcessor(config);
    }
    else if (type == "Image"){
        processorPtr = new ImageProcessor(config);
    }
    else if(type == "Audio"){
        processorPtr = new AudioProcessor(config);
    }
    else{
        throw config::InvalidProcessorTypeException("Invalid Processor Type Provided: \"" + type + "\". Please provide a valid Processor Type");
    }

    return *processorPtr;
}

ProcessorFactory::~ProcessorFactory() noexcept{
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
    delete processorPtr;
}