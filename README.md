# Movie Theater Seat Reservation System (C)

A console-based seat reservation program that loads a theater seating layout from a file, allows users to purchase up to **4 tickets**, reserves available seats in real time, and saves the updated seating chart to an output file.

---

## Features
- File-based seat map input (rows/columns + seat layout)
- Purchase up to **4 tickets per transaction**
- Interactive seat selection using **Row + Seat number** (example: `B3`)
- Prevents double-booking by marking sold seats as **`X`**
- Displays a formatted seat map after each selection
- Writes updated theater layout to an output file

---

## Project Highlights

- Developed a seat reservation system that allows users to purchase up to **4 tickets** and select available seats with real-time updates.
- Implemented **file handling** to store and retrieve seating arrangements, ensuring accurate tracking of seat availability.
- Added **input validation and error handling** to prevent invalid seat selections and enforce ticket purchase limits.
- Designed a **2D array-based seat management system**, marking sold seats with `X` and displaying a formatted seat map for easy selection.


## How It Works
1. Reads an input file containing the number of rows, columns, and seating layout.
2. Stores the seating data in a **2D array**.
3. Prompts the user to select seats until the requested number of tickets is reserved.
4. Marks sold seats with `X`.
5. Saves the updated seating chart to a new output file.

---
