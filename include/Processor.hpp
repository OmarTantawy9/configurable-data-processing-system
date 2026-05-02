#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Configuration.hpp"

class Processor {

protected:
    const Configuration &config;

public:

    Processor(const Configuration &config);
    virtual ~Processor() noexcept;
    virtual void process() = 0;

};

class TextProcessor : public Processor {

public:
    TextProcessor(const Configuration &config);
    ~TextProcessor() noexcept;
    void process();
};

class NumericProcessor : public Processor {

public:
    NumericProcessor(const Configuration &config);
    ~NumericProcessor() noexcept;
    void process();
};

class ImageProcessor : public Processor {

public:
    ImageProcessor(const Configuration &config);
    ~ImageProcessor() noexcept;
    void process();
};

class AudioProcessor : public Processor {

public:
    AudioProcessor(const Configuration &config);
    ~AudioProcessor() noexcept;
    void process();
};

#endif //  PROCESSOR_H