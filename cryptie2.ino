String clear = "message";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  String a = Encrypt(clear);
  Serial.println(a);
  Serial.println(Decrypt(a));
}

void loop() {
}

String Encrypt(String clearText) {
  String encText;
  String encryptedText;
  int length = clearText.length();
  int lastIndex = length - 1;
  int halfLength = length / 2;

  if ((length % 2) == 0) {
    for (int i = 0; i < halfLength; i++) {
      encryptedText = encryptedText + clearText[i];
      encryptedText = encryptedText + clearText[lastIndex - i];
    }
  } else {
    for (int i = 0; i < halfLength; i++) {
      encryptedText = encryptedText + clearText[i];
      encryptedText = encryptedText + clearText[lastIndex - i];
    }
    encryptedText = encryptedText + clearText[halfLength];
  }
  encryptedText.toUpperCase();
  //Serial.println(encryptedText);
  int c = encryptedText.length();

  for (int i = 0; i < c; i++) {
    int a = encryptedText[i] + 10;
    char achar = a;
    //Serial.println(achar);
    encText = encText + achar;
  }
  return encText;
}

String Decrypt(String encText) {
  String scrambledText;
  int c = encText.length();
  char clearText[c];
  int lastIndex = c - 1;
  int halfLength;
  if (c % 2 == 0) {
    halfLength = c / 2;
  } else {
    halfLength = (c / 2) + 1;
  }

  for (int i = 0; i < c; i++) {
    int a = encText[i] - 10;
    char achar = a;
    scrambledText = scrambledText + achar;
  }
  if (c % 2 == 0) {
    for (int i = 0; i < halfLength; i++) {
      clearText[i] = scrambledText[2 * i];
      clearText[lastIndex - i] = scrambledText[2 * i + 1];
    }
  }
  else{
    for (int i = 0; i < halfLength; i++) {
      clearText[i] = scrambledText[2 * i];
      if ((halfLength - i) > 1){
        clearText[lastIndex - i] = scrambledText[2 * i + 1];
      }

    }
  }

  return String(clearText);
}
