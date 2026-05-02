# C++ Dynamic Processor System

## Project Overview

This project is very simple a C++ application designed to enhance understanding of core C++ concepts, including:

- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- Templates
- File Handling
- Exception Handling

The application focuses on creating a dynamic and extensible system for processing different types of data based on user-provided configuration files.

---

## Key Features

### 1. Dynamic Configuration Parsing
- Reads and parses a text-based configuration file.
- Supports nested structures using dot (`.`) notation for hierarchical options.
- Dynamically selects the appropriate processor type based on configuration.

### 2. Processor Abstraction
- Uses an abstract base class `Processor`.
- Derived classes include:
  - `TextProcessor`
  - `NumericProcessor`
  - `ImageProcessor`
  - `AudioProcessor`
- Utilizes polymorphism for runtime behavior selection.

### 3. Factory Design Pattern
- Implements `ProcessorFactory`.
- Responsible for creating processor objects based on configuration input.
- Decouples object creation from business logic.

### 4. Template-Based Processing
- Uses C++ templates to process collections of data generically.
- Ensures reusable and type-agnostic processing logic.

### 5. Exception Handling
- Handles:
  - Invalid configuration files
  - Missing files
  - Unsupported processor types
- Ensures application stability under unexpected conditions.

---

## Project Workflow

### 1. Configuration File
Create a configuration file (e.g., `settings.txt`) that defines the processor type and related options.

Example:
```
processor.type=TextProcessor
processor.mode=advanced
```


---

### 2. Dynamic Processor Creation
- The system reads the configuration file at runtime.
- It selects and instantiates the appropriate processor using the factory.

---

### 3. Data Processing
- Main simulates processing of data after constructing the correct Data Processor.

---

### 4. Robust Error Handling
The system gracefully handles:
- Missing configuration files
- Invalid processor types
- Runtime processing errors
