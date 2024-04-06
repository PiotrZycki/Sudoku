


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

  *  File: `plik_wejsciowy.txt`

      <style scoped>
      table {
        font-size: 8px;
      }
      </style>

     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 7 | 0 |
     | - | - | - | - | - | - | - | - | - |
     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
     | 0 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
     | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 5 |
     | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
     | 0 | 9 | 0 | 0 | 8 | 0 | 0 | 0 | 0 |
     | 7 | 0 | 0 | 0 | 0 | 0 | 0 | 6 | 0 |
     | 0 | 0 | 0 | 0 | 5 | 8 | 0 | 0 | 0 |
     | 1 | 0 | 0 | 4 | 0 | 0 | 0 | 0 | 7 |
  
  *  Program arguments:

     `rozwiazuj ../plik_wejsciowy.txt ../wynik.txt`

  
  *  Output:

     ![Solution][solution]



[solution]: https://github.com/PiotrZycki/Sudoku/assets/96142056/3fc64d82-4dd8-4362-b92f-e55d6877b388
