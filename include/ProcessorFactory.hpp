#ifndef PROCESSOR_FACTORY_H
#define PROCESSOR_FACTORY_H

#include "Processor.hpp"

class ProcessorFactory {
    
    Processor *processorPtr;

public:
    ProcessorFactory();
    Processor& create(Configuration &config);
    virtual ~ProcessorFactory() noexcept;
};

#endif // PROCESSOR_FACTORY_H