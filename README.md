# Sudoku
A simple program generating, checking and solving sudoku.

Input accepts .txt file filled with numbers.
Numbers are arranged in 9 rows and columns.
Empty fields are represented as 0.

## Features

  *  Print
      Reads numbers from file and shows them on the board.

      `wypisz <input_file.txt>`

  
  *  Check
      Reads file and checks if sudoku is solvable

      `sprawdz <input_file.txt>`


  *  Generate
      Creates random sudoku in one of the 3 difficulty levels: easy (latwe), medium (srednie), hard (trudne)

     `generuj <difficulty_level> <output_file.txt>`

     
  *  Solve
     Solves sudoku from file and puts the solution into different file.

     `rozwiazuj <input_file.txt> <output_file.txt>`



### Example:

  *  File: plik_wejsciowy.txt



     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 7 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 5 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 9 | 0 | 0 | 8 | 0 | 0 | 0 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 7 | 0 | 0 | 0 | 0 | 0 | 0 | 6 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 0 | 0 | 0 | 5 | 8 | 0 | 0 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 1 | 0 | 0 | 4 | 0 | 0 | 0 | 0 | 7 |
  
  *  Program arguments:

     `rozwiazuj ../plik_wejsciowy.txt ../wynik.txt`

  
  *  Output:

  `
     Rozwiązanie:
      -------------------------------------
      |  3  1  4  |  2  6  5  |  8  7  9  |
      |  5  6  7  |  8  1  9  |  2  3  4  |
      |  8  2  9  |  3  4  7  |  1  5  6  |
      -------------------------------------
      |  2  7  3  |  1  9  4  |  6  8  5  |
      |  4  5  8  |  6  7  2  |  9  1  3  |
      |  6  9  1  |  5  8  3  |  7  4  2  |
      -------------------------------------
      |  7  3  5  |  9  2  1  |  4  6  8  |
      |  9  4  6  |  7  5  8  |  3  2  1  |
      |  1  8  2  |  4  3  6  |  5  9  7  |
      -------------------------------------
`
     
