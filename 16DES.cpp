#include <iostream>
#include <bitset>
#include <string>
#include <stdexcept>

using namespace std;

// Initial permutation table
const int IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

// Final permutation table
const int FP[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

// Simple bit permutation function
bitset<64> permute(const bitset<64>& input, const int* table) {
    bitset<64> result;
    for (int i = 0; i < 64; ++i) {
        result[63 - i] = input[64 - table[i]];
    }
    return result;
}

// Function to encrypt using simplified DES
bitset<64> des_encrypt(const bitset<64>& block, const bitset<64>& key) {
    bitset<64> permuted_block = permute(block, IP); // Initial Permutation
    bitset<64> encrypted_block = permute(permuted_block, FP); // Final Permutation
    return encrypted_block;
}

// Helper function to convert hex string to bitset
bitset<64> hex_to_bitset(const string& hex) {
    bitset<64> result;
    for (size_t i = 0; i < hex.size(); ++i) {
        char c = hex[i];
        uint8_t val = (c >= 'A') ? (c >= 'a') ? (c - 'a' + 10) : (c - 'A' + 10) : (c - '0');
        for (int j = 0; j < 4; ++j) {
            result[63 - (i * 4 + j)] = (val >> (3 - j)) & 1;
        }
    }
    return result;
}

int main() {
    // Example 64-bit plaintext and key
    string plaintext_str = "0001001100110100010101110111100110011011101111001101111111110000";
    string key_str = "133457799BBCDFF1";  // 64-bit key (hexadecimal)

    // Convert strings to bitsets
    bitset<64> plaintext(plaintext_str);
    bitset<64> key = hex_to_bitset(key_str);

    // Display input
    cout << "Plaintext (before encryption): " << plaintext << endl;
    cout << "Key: " << key << endl;

    // Encrypt using simplified DES
    bitset<64> encrypted_block = des_encrypt(plaintext, key);

    // Display output
    cout << "Encrypted (after encryption): " << encrypted_block << endl;

    return 0;
}