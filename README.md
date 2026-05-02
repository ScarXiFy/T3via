# T3via

T3via is an interactive, command-line trivia game developed in C. Designed as a comprehensive software project, it challenges players across four distinct levels of difficulty and subject matter, ranging from general knowledge to complex mathematics.

## 🚀 Features

The game consists of **40 questions** divided into four specialized levels, each with its own scoring weight and format:

*   **Level I: True or False** (1 point each)
    *   Tests foundational knowledge with simple boolean statements.
*   **Level II: Multiple Choice** (2 points each)
    *   Covers a broad range of topics including biology, technology, and history.
*   **Level III: Identification** (3 points each)
    *   Requires precise text input to identify specific terms, people, or locations.
*   **Level IV: Mathematical Reasoning** (5 points each)
    *   Challenging word problems and logic puzzles in a multiple-choice format.

### Key Gameplay Mechanics
*   **Randomized Questions:** Within each level, questions are selected in a random order to ensure a unique experience every time you play.
*   **Real-time Scoring:** Instant feedback on your answers and a summary of points at the end of each level.
*   **Comprehensive Grading:** A final score out of 110 points is converted into a letter grade (A+ through F, or Fail).

## 🛠️ Technologies Used

*   **Language:** C
*   **Libraries:**
    *   `stdio.h`, `stdlib.h`: Standard input/output and utility functions.
    *   `conio.h`: Console I/O for interactive keyboard input.
    *   `time.h`: Used for seeding the random number generator.
    *   `stdbool.h`: Standard boolean types for logic handling.

## 📥 Installation

To run T3via locally, you will need a C compiler (such as GCC) and a Windows-compatible terminal environment (as the game utilizes `conio.h` and `system("cls")`).

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/ScarXiFy/T3via.git
    cd T3via
    ```

2.  **Compile the Code:**
    Using GCC:
    ```bash
    gcc "FINALS Software Project Code.c" -o T3via.exe
    ```

3.  **Run the Application:**
    ```bash
    ./T3via.exe
    ```

## 🎮 How to Play

1.  **Main Menu:**
    *   Press `S` to start a new game.
    *   Press `H` to view the help menu and grading scale.
    *   Press `Q` to exit the application.
2.  **Registration:** Enter your name when prompted to personalize your session.
3.  **Answering Questions:**
    *   **True/False:** Press `1` for True and `0` for False.
    *   **Multiple Choice:** Press the corresponding number (`1-4`) for your choice.
    *   **Identification:** Type the full answer and press `Enter`.
4.  **Results:** After completing all 40 questions, your total score and final grade will be displayed.

## 📊 Grading Scale

| Score Range | Grade |
| :--- | :--- |
| 101 - 110 | A+ |
| 96 - 100 | A |
| 91 - 95 | B |
| 86 - 90 | C |
| 81 - 85 | D |
| 76 - 80 | E |
| 70 - 75 | F |
| Below 70 | FAIL |

## 👤 Author

**John Enrico D. Lauron**
Grade 12 - T3

---
*Created as a FINALS Software Project — December 2022.*
