```text   
  ____ ___  _______(_)___
 / __ `/ / / / ___/ / __ \
/ /_/ / /_/ / /  / / /_/ /
\__, /\__,_/_/  /_/\____/
  /_/        
```
# Quick RISC-V Open Compiler (qurio-C)

## 📌 Table of Contents
- [About](#-about)
- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Configuration](#-configuration)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)

## 📖 About
qurio-C is an open-source compiler designed to compile a C/C++-like language into RISC-V assembly, enabling low-level code generation for RISC-V architectures.

## ✨ Features
1. Language Support
    - Supports a **C/C++-like syntax** for simple code adoption
    - Includes essential **C-styled control structures**
    - Partial and extending to full support to C++ **object-oriented programming features**
    - Customized **optimization** for certain commonly used features to assembly level
2. Compilation Pipline
    - **Lexical analysis** with qurio tokenizer
    - **Parsing** with an abstract syntax tree (AST) with a Deterministic Finite Automaton (DFA)
    - **Symantic Analysis** to catch exceptions or enforce language rules
    - **Optimizer** to improve performance
    - **Code generation** targeting **RISC-V assembly** set
3. RISC-V Service
    - Generates **optimized RISC-V assembly code**
    - Supports **RV32I / RV64I** base instruction sets
    - Supports **floating-point (F)** extensions
    - Efficient **register allocation** and **stack management**
    - Supports **inline assembly** for low-level control
4. Extensibility & Open Source Development
   - **Modular compiler** architecture for easy extension
   - Supports **custom language features** or **experimental extensions**
   - Open-source repository with **contributor-friendly documentation**
5. Optimization
    - To be provided

## 🚀 Installation
### Prerequisites
- WSL 2
- Ubuntu 22.04
- CLion 2024.3.3 or above
- C++ 23 or above
- CMake 3.22.1 or above

### Steps
```sh
# Clone the repository
git clone https://github.com/Xiaobai2-2022/qurio
cd qurio
```

## 🛠 Usage

To be provided

## ⚙️ Configuration

To be provided

## 🤝 Contributing
Contributions are welcome! Follow these steps:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## 📜 License

To be provided

## 📬 Contact
- **Project Manager / Lead Programmer:** Zhifan (Xiaobai2-2022)
- **Email:** Z2367LI [at] UWATERLOO [dot] CA
- **GitHub:** [Xiaobai2-2022](https://github.com/Xiaobai2-2022)

