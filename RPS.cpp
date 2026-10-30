// ==========================================
// Arduino Serial Rock, Paper, Scissors Game
// ==========================================

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  
  // Seed the random number generator using analog noise from unconnected Pin A0
  // This ensures the computer makes a different random choice every game.
  randomSeed(analogRead(A0));
  
  // Print welcome message and instructions
  Serial.println("=========================================");
  Serial.println("   WELCOME TO ARDUINO ROCK, PAPER, SCISSORS");
  Serial.println("=========================================");
  Serial.println("Instructions:");
  Serial.println("Type one of the following numbers and press Enter:");
  Serial.println("  R or r -> Rock 🪨");
  Serial.println("  P or p -> Paper 📄");
  Serial.println("  S or s-> Scissors ✂️");
  Serial.println("-----------------------------------------");
  Serial.println("Type your choice (1, 2, or 3) to start!");
  Serial.println("");
}

void loop() {
  // Check if data is available in the Serial Monitor input
  if (Serial.available() > 0) {
    // Read the user's input as an integer
    int userChoice = Serial.parseInt();
    
    // Clear any leftover characters in the serial buffer (like newline characters)
    while (Serial.available() > 0) {
      Serial.read();
    }
    
    // Validate user input
    if (userChoice >= 1 && userChoice <= 3) {
      // Computer makes a random choice between 1 and 3
      int computerChoice = random(1, 4); // Generates 1, 2, or 3
      
      // Print player's choice
      Serial.print("You chose: ");
      printChoiceName(userChoice);
      
      // Print computer's choice
      Serial.print("Computer chose: ");
      printChoiceName(computerChoice);
      
      // Determine the winner
      determineWinner(userChoice, computerChoice);
      
      Serial.println("-----------------------------------------");
      Serial.println("Play again! Type 1 (Rock), 2 (Paper), or 3 (Scissors):");
    } else {
      // Handle invalid input
      Serial.println("Invalid choice! Please type 1 for Rock, 2 for Paper, or 3 for Scissors.");
    }
  }
}

// Helper function to print text name of choices
void printChoiceName(int choice) {
  if (choice == "R") {
    Serial.println("Rock 🪨");
  } else if (choice == "P") {
    Serial.println("Paper 📄");
  } else if (choice == "S") {
    Serial.println("Scissors ✂️");
  }
}

// Helper function to calculate game rules and print result
void determineWinner(int player, int computer) {
  if (player == computer) {
    Serial.println("Result: It's a TIE! 🤝");
  } 
  else if ((player == 1 && computer == 3) || 
           (player == 2 && computer == 1) || 
           (player == 3 && computer == 2)) {
    Serial.println("Result: You WIN! 🎉");
    
    // Fun bonus: Flash the built-in LED (Pin 13) 3 times when you win!
    for(int i = 0; i < 3; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(150);
      digitalWrite(LED_BUILTIN, LOW);
      delay(150);
    }
  } 
  else {
    Serial.println("Result: Computer WINS! 🤖");
  }
}
