const char message[] = "SOS ";

struct morse {
  char letter;
  char* code;
};

morse morse_table[] = {
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', "-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  { '0', "-----" },
  { '1', ".----" },
  { '2', "..---" },
  { '3', "...--" },
  { '4', "....-" },
  { '5', "....." },
  { '6', "-...." },
  { '7', "--..." },
  { '8', "---.." },
  { '9', "----." },
  { '.', ".-.-.-" },
  { ',', "--..--" },
  { '?', "..--.." },
  { '!', "-.-.--" },
  { '/', "-..-." },
  { '(', "-.--." },
  { ')', "-.--.-" },
  { '&', ".-..." },
  { ':', "---..." },
  { ';', "-.-.-." },
  { '=', "-...-" },
  { '+', ".-.-." },
  { '-', "-....-" },
  { '_', "..--.-" },
  { '"', ".-..-." },
  { '$', "...-..-" },
  { '@', ".--.-." },
  { ' ', "/" }
};

char* morse_lookup(char c) {
  if (c >= 'a' && c <= 'z') {
    c = c - 32;
  }

  for (int i = 0; i < sizeof(morse_table) / sizeof(morse); i++) {
    if (c == morse_table[i].letter) {
      return morse_table[i].code;
    }
  }
  return NULL;
}



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  //Serial.begin(9600);
}

void loop() {


  for (int i = 0; i < ((sizeof(message) / sizeof(message[0])) - 1); i++) {
    Serial.print(message[i]);
    char* code = morse_lookup(message[i]);
    Serial.print(" ");

    for (int x = 0; x <= (sizeof(code) / sizeof(code[0])); x++) {
      Serial.print(code[x]);
      switch (code[x]) {
        case '.':
          digitalWrite(LED_BUILTIN, HIGH);
          delay(100);
          digitalWrite(LED_BUILTIN, LOW);
          delay(300);
          break;
        case '-':
          digitalWrite(LED_BUILTIN, HIGH);
          delay(300);
          digitalWrite(LED_BUILTIN, LOW);
          delay(300);
          break;
        case '/':
          delay(700);
          break;
        default:
          break;
      }
    }
    delay(300);
  }
  Serial.println("restart");
}