#include <stdio.h>
#include <stdlib.h>
#include "unif01.h"
#include "bbattery.h"
#include "ufile.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_binary_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filePath = argv[1];
    
    // Setze die Puffergröße auf 16kB
    int bufferSize = 16384;
    
    // Erstelle einen externen Generator, der Bits aus der Datei liest,
    // mit einer expliziten Puffergröße von 16kB
    unif01_Gen *gen = ufile_CreateReadBin(filePath, bufferSize);

    if (gen == NULL) {
        fprintf(stderr, "Fehler beim Erstellen des Generators. Stellen Sie sicher, dass die Datei existiert und lesbar ist.\n");
        return EXIT_FAILURE;
    }

    // Führe BigCrush auf diesen Generator aus
    printf("Führe BigCrush auf %s aus...\n", filePath);
    bbattery_BigCrush(gen);

    // Räume den Generator auf
    ufile_DeleteReadBin(gen);

    return EXIT_SUCCESS;
}
