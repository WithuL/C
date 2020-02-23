char ToLowerCase(char str[]) {
    int i = 0;
    int size = 0;
    while (str[size] != 0) {
        size++;
    }
    for (i; i < size; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    int j = 0;
    for (j; j < size; j++) {
        printf("%c", str[j]);
    }
}