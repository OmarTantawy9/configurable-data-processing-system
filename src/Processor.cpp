#include "../include/Processor.hpp"

#include <iostream>

Processor::Processor(const Configuration &config) : config(config) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

Processor::~Processor() noexcept{
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}


TextProcessor::TextProcessor(const Configuration &config) : Processor(config) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
};

TextProcessor::~TextProcessor() noexcept{
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

void TextProcessor::process(){
    std::clog << "[INFO] " << __PRETTY_FUNCTION__  << std::endl << std::endl;
    std::cout << "Processing Text with Configuration" << std::endl << config << std::endl;
}


NumericProcessor::NumericProcessor(const Configuration &config) : Processor(config) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
};

NumericProcessor::~NumericProcessor() noexcept{
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

void NumericProcessor::process(){
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl << std::endl;
    std::cout << "Processing Numeric Value with Configuration" << std::endl << config << std::endl;

}


ImageProcessor::ImageProcessor(const Configuration &config) : Processor(config) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
    
};

ImageProcessor::~ImageProcessor() noexcept{
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

void ImageProcessor::process(){
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl << std::endl;
    std::cout << "Processing Image with Configuration" << std::endl << config << std::endl;
}

AudioProcessor::AudioProcessor(const Configuration &config) : Processor(config) {
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
};

AudioProcessor::~AudioProcessor() noexcept{
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl;
}

void AudioProcessor::process(){
    std::clog << "[INFO] " << __PRETTY_FUNCTION__ << std::endl << std::endl;
    std::cout << "Processing Audio with Configuration" << std::endl << config << std::endl;
}