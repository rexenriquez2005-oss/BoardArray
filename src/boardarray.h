#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            if (index == 0) {
                array[0] = *entry;
                index++;
                return;
            }
            int inPos = -1;
            for (int i = 0; i < index; i++) {
                if (entry->compare(&array[i])) { 
                    inPos = i;
                    break;
                }
            }
            if (inPos == -1 && index < SIZE) {
                array[index] = *entry;
                index++;
                return;
            }
            if (inPos == -1 && index == SIZE) {
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }
            if (index == SIZE) {
                for (int i = SIZE - 1; i > inPos; i--) {
                    array[i] = array[i - 1];
                }
                array[inPos] = *entry;
            } else {
                for (int i = index; i > inPos; i--) {
                    array[i] = array[i - 1];
                }
                array[inPos] = *entry;
                index++;
            }
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};