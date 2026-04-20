int maxDistance(int* colors, int colorsSize) {
    int i = 0, j = colorsSize - 1;
    while (colors[i] == colors[colorsSize - 1]) i++;
    while (colors[j] == colors[0]) j--;
    return (colorsSize - 1 - i > j) ? (colorsSize - 1 - i) : j;
}
