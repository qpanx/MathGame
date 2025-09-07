📘 Math Quiz Game (C++)
🎮 Overview

This is a Math Quiz Game built with C++.
The game generates random math questions based on difficulty level and operation type.
The player answers a set of questions, and at the end, the program displays results such as correct answers, wrong answers, and whether the player passed or failed.

🚀 Features

Multiple difficulty levels:

Easy (1–10 numbers)

Medium (10–50 numbers)

Hard (50–100 numbers)

Mix (random difficulty each question)

Operation modes:

Addition (+)

Subtraction (−)

Multiplication (×)

Division (÷)

Mix (random operations each question)

Pass/Fail system (based on correct vs wrong answers).

Colored screen feedback:

✅ Green for correct answers

❌ Red with beep sound for wrong answers

Ability to replay the quiz multiple times.

🛠️ How to Run

Clone this repository:

git clone https://github.com/your-username/math-quiz-game.git
cd math-quiz-game


Compile the code:

g++ -o MathQuizGame main.cpp


Run the game:

./MathQuizGame

📷 Demo (Example Run)
How Many Questions do you want to answer? 3
Enter Questions Level [1] Easy, [2] Medium , [3] Hard , [4] Mix ? 2
Enter Operation type [1] Add, [2] Subtract , [3] Multiplication , [4] Division , [5] Mix ? 5

Question [1/3] 
15 * 7
_____________
Your Answer: 105
Right Answer :-)

Question [2/3] 
33 - 20
_____________
Your Answer: 14
Wrong Answer :-(
The right answer is: 13

___________________________

 Final Results is Pass :-)
___________________________

Number of Questions: 3
Questions Level    : Medium
Operation Type     : Mix
Number of Right Answers: 2
Number of Wrong Answers: 1
___________________________

📂 Project Structure
├── main.cpp    # Source code for the Math Quiz Game
├── README.md   # Documentation file

🧠 Concepts Used

Enums for difficulty levels & math operations.

Structs for storing question data & quiz results.

Functions for modularity (question generation, checking answers, printing results).

Random number generation with rand().

Control flow (loops, conditions, switch statements).

System commands (cls, color) for Windows terminal effects.

🔮 Future Improvements

Add timer mode (answer within limited seconds).

Store scores in a file (leaderboard).

Support floating-point division results.

Make cross-platform (Linux/macOS without Windows system("color")).
