/**
 * \file
 *
 * \brief SAM Crypto Acceleration (CYRA).
 *
 * Copyright (c) 2017-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
#ifndef HPL_CRYA_INCLUDED
#define HPL_CRYA_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup CRYA functions address
 */
#define LIBCRYA_BASE_ADDRESS 0x02001900
#define CRYA_SHA_ADDRESS (LIBCRYA_BASE_ADDRESS + 0x0)
#define CRYA_AES_ENC_ADDRESS (LIBCRYA_BASE_ADDRESS + 0x4)
#define CRYA_AES_DEC_ADDRESS (LIBCRYA_BASE_ADDRESS + 0x8)
#define CRYA_GF_MULT128_ADDRESS (LIBCRYA_BASE_ADDRESS + 0xC)
/** @} */

/**
 * \brief Type definition for SHA function.
 *
 * \param hash_in_out[In/out]:  A pointer to a hash location (hash input and output)
 * \param data[In]:             A pointer to a 512 bit data block
 * \param ram_buf[In]:          A pointer to a RAM buffer (256B needed for internal algorithm)
 */
typedef void (*crya_sha_process_t)(uint32_t hash_in_out[8], const uint8_t data[64], uint32_t ram_buf[64]);

/**
 * \brief Type definition for AES encrypt function.
 *
 * \param keys[in]:    A pointer to 128-bit key
 * \param key_len[in]: Number of 32-bit words comprising the key, 4 for 128-bit key
 * \param src[in]:     A pointer to a 128-bit data block to be encrypted
 * \param dst[out]:    A pointer to a 128-bit encrypted data
 */
typedef void (*crya_aes_encrypt_t)(const uint8_t *keys, uint32_t key_len, const uint8_t *src, uint8_t *dst);

/**
 * \brief Type definition for AES decrypt function.
 *
 * \param keys[in]:    A pointer to 128-bit key
 * \param key_len[in]: Number of 32-bit words comprising the key, 4 for 128-bit key
 * \param src[in]:     A pointer to a 128-bit data block to be decrypted
 * \param dst[out]:    A pointer to a 128-bit decrypted data
 */
typedef void (*crya_aes_decrypt_t)(const uint8_t *keys, uint32_t key_len, const uint8_t *src, uint8_t *dst);

/**
 * \brief Type definition for GF(2^128)  multiplication.
 *
 * \param block1[In]:  A pointer to 128-bit data blocks that are to be multiplied
 * \param block2[In]:  A pointer to 128-bit data blocks that are to be multiplied
 * \param dst[out]:    A pointer to a location for storing the result
 */
typedef void (*crya_gf_mult128_t)(const uint32_t *block1, const uint32_t *block2, uint32_t *dst);

/** SHA function */
#define crya_sha_process ((crya_sha_process_t)(CRYA_SHA_ADDRESS | 0x1))

/** AES encrypt function */
#define crya_aes_encrypt ((crya_aes_encrypt_t)(CRYA_AES_ENC_ADDRESS | 0x1))

/** AES decrypt function */
#define crya_aes_decrypt ((crya_aes_decrypt_t)(CRYA_AES_DEC_ADDRESS | 0x1))

/** GCM function */
#define crya_gf_mult128 ((crya_gf_mult128_t)(CRYA_GF_MULT128_ADDRESS | 0x1))

/*
Example of using CRYA APIs:

bool test_sha(void)
{
    uint8_t input_data[] = {
        0x61, 0x62, 0x63, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
    };
    uint32_t hash_in_out[8] = {
        0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
    };
    uint32_t hash_expect[8] = {
        0xba7816bf, 0x8f01cfea, 0x414140de, 0x5dae2223,
        0xb00361a3, 0x96177a9c, 0xb410ff61, 0xf20015ad
    };
    uint32_t ram_buf[64];
    uint32_t i;

    crya_sha_process(hash_in_out, input_data, ram_buf);
    for (i = 0; i < 8; i++) {
        if (hash_in_out[i] != hash_expect[i]) {
            break;
        }
    }
    if (i < 8) {
        return false;
    } else {
        return true;
    }
}

bool test_aes(void)
{
    // Example Vectors From FIPS-197
    //                 PLAINTEXT: 00112233445566778899aabbccddeeff
    //                 KEY: 000102030405060708090a0b0c0d0e0f
    //                 CIPHER: 69c4e0d86a7b0430d8cdb78070b4c55a

    const uint8_t plaintext[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
    };
    const uint8_t key[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
    const uint8_t cipher[] = {
        0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
        0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a
    };
    uint8_t result[16];
    uint32_t i;

    crya_aes_encrypt(key, 4, plaintext, result);

    for (i = 0; i < 16; i++) {
        if (result[i] != cipher[i]) {
            break;
        }
    }
    if (i < 16) {
        return false;
    }

    crya_aes_decrypt(key, 4, cipher, result);

    for (i = 0; i < 16; i++) {
        if (result[i] != plaintext[i]) {
            break;
        }
    }
    if (i < 16) {
        return false;
    } else {
        return true;
    }
}

bool test_gcm(void)
{
    // The input is
    //              X: 73a23d80121de2d5a850253fcf43120e
    //              V: d609b1f056637a0d46df998d88e5222a
    //              The output result should be
    //              Z: 6b0be68d67c6ee03ef7998e399c01ca4

    const uint32_t block1[4] = {0x803da273, 0xd5e21d12, 0x3f2550a8, 0xe1243cf};
    const uint32_t block2[4] = {0xf0b109d6, 0xd7a6356, 0x8d99df46, 0x2a22e588};
    const uint32_t expected[4] = {0x8de60b6b, 0x3eec667, 0xe39879ef, 0xa41cc099};

    uint32_t result[4];
    uint32_t i;

    crya_gf_mult128(block1, block2, result);
    for (i = 0; i < 4; i++) {
        if (result[i] != expected[i]) {
            break;
        }

    }
    if (i < 4) {
        return false;
    } else {
        return true;
    }
}
*/

#ifdef __cplusplus
}
#endif

#endif /* HPL_CRYA_INCLUDED */
