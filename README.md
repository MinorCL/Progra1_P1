# 📝 Sistema de Gestión de Exámenes (C++)

Proyecto de curso universitario en **C++ orientado a objetos**: una aplicación de consola para crear un banco de preguntas y armar exámenes (tests) a partir de ellas, con control de puntaje y de reutilización de preguntas.

## ✨ Características

- **Banco de preguntas**: cada pregunta (`Question`) tiene su texto, puntaje, un conjunto de respuestas (`Answer`, con una marcada como correcta) y un contador de veces usada.
- **Identificación única**: cada pregunta se registra con un `ID` autoincremental (contador estático), permitiendo consultarla individualmente desde el banco (`IDContainer`).
- **Creación de exámenes**: un `Test` se arma seleccionando preguntas existentes por ID. Regla de negocio: una pregunta no puede añadirse a más de 3 exámenes distintos.
- **Gestión completa por consola**: crear examen, ver todos los exámenes, eliminar examen por nombre, ver banco de preguntas, consultar pregunta por ID, consultar examen por nombre, agregar pregunta nueva.
- **Arreglos dinámicos propios**: `Test` maneja su arreglo de preguntas (`ID**`) con capacidad inicial y una función `resize()` que lo duplica cuando se llena, en lugar de usar `std::vector`.

## 🗂️ Estructura del proyecto

```
├── Answer.h / Answer.cpp                  # Respuesta de una pregunta (texto + si es correcta)
├── AnswerContainer.h / .cpp               # Contenedor de respuestas de una pregunta
├── Question.h / Question.cpp              # Pregunta: texto, puntaje, respuestas, usos
├── QuestionContainer.h / .cpp             # Contenedor de preguntas
├── ID.h / ID.cpp                          # Identificador único autoincremental por pregunta
├── IDContainer.h / .cpp                   # Banco de preguntas indexado por ID
├── Test.h / Test.cpp                      # Examen: nombre + arreglo dinámico de preguntas
├── TestContainer.h / .cpp                 # Contenedor de exámenes creados
├── Controller.h / Controller.cpp          # Lógica del programa y menú interactivo
└── Proyecto.cpp                           # Punto de entrada (main)
```

## ▶️ Compilación y ejecución

**Con Visual Studio:** abre la solución y compila (`Ctrl+F5`).

**Con g++:**
```bash
g++ -std=c++17 *.cpp -o examenes
./examenes
```

> El programa incluye 3 preguntas de ejemplo precargadas al iniciar (`initializeDefaultQuestions()`).

## 🎓 Contexto

Proyecto académico de Programación 2 en C++, centrado en manejo de memoria dinámica, arreglos redimensionables manuales y composición de clases (Question → Answer, Test → Question vía ID).