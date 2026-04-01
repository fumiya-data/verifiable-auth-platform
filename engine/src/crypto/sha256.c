#include "sha256.h"

#include <string.h>

static const uint32_t auth_sha256_initial_state[8] = {
    0x6a09e667u, 0xbb67ae85u, 0x3c6ef372u, 0xa54ff53au,
    0x510e527fu, 0x9b05688cu, 0x1f83d9abu, 0x5be0cd19u,
};

static const uint32_t auth_sha256_round_constants[64] = {
    0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u,
    0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u,
    0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u,
    0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u,
    0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu,
    0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau,
    0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u,
    0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u,
    0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcu, 0x53380d13u,
    0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u,
    0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u,
    0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u,
    0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u,
    0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u,
    0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u,
    0x90befffau, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u,
};

static uint32_t auth_sha256_rotate_right(uint32_t value, uint32_t shift)
{
    return (value >> shift) | (value << (32u - shift));
}

static uint32_t auth_sha256_choose(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (~x & z);
}

static uint32_t auth_sha256_majority(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

static uint32_t auth_sha256_big_sigma0(uint32_t value)
{
    return auth_sha256_rotate_right(value, 2u) ^
           auth_sha256_rotate_right(value, 13u) ^
           auth_sha256_rotate_right(value, 22u);
}

static uint32_t auth_sha256_big_sigma1(uint32_t value)
{
    return auth_sha256_rotate_right(value, 6u) ^
           auth_sha256_rotate_right(value, 11u) ^
           auth_sha256_rotate_right(value, 25u);
}

static uint32_t auth_sha256_small_sigma0(uint32_t value)
{
    return auth_sha256_rotate_right(value, 7u) ^
           auth_sha256_rotate_right(value, 18u) ^
           (value >> 3u);
}

static uint32_t auth_sha256_small_sigma1(uint32_t value)
{
    return auth_sha256_rotate_right(value, 17u) ^
           auth_sha256_rotate_right(value, 19u) ^
           (value >> 10u);
}

static uint32_t auth_sha256_load_be32(const uint8_t bytes[4])
{
    return ((uint32_t)bytes[0] << 24u) |
           ((uint32_t)bytes[1] << 16u) |
           ((uint32_t)bytes[2] << 8u) |
           (uint32_t)bytes[3];
}

static void auth_sha256_store_be32(uint32_t value, uint8_t bytes[4])
{
    bytes[0] = (uint8_t)(value >> 24u);
    bytes[1] = (uint8_t)(value >> 16u);
    bytes[2] = (uint8_t)(value >> 8u);
    bytes[3] = (uint8_t)value;
}

static void auth_sha256_store_be64(uint64_t value, uint8_t bytes[8])
{
    bytes[0] = (uint8_t)(value >> 56u);
    bytes[1] = (uint8_t)(value >> 48u);
    bytes[2] = (uint8_t)(value >> 40u);
    bytes[3] = (uint8_t)(value >> 32u);
    bytes[4] = (uint8_t)(value >> 24u);
    bytes[5] = (uint8_t)(value >> 16u);
    bytes[6] = (uint8_t)(value >> 8u);
    bytes[7] = (uint8_t)value;
}

/**
 * @brief Compress one 512-bit block into the running SHA-256 state.
 *
 * The function expands the 16 input words into the full 64-word message
 * schedule, runs the 64 rounds, and folds the local working words back into
 * the context state.
 */
static void auth_sha256_transform(auth_sha256_ctx_t *ctx,
                                  const uint8_t block[AUTH_SHA256_BLOCK_BYTES])
{
    uint32_t schedule[64];
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    uint32_t e;
    uint32_t f;
    uint32_t g;
    uint32_t h;

    for (size_t index = 0; index < 16u; ++index) {
        schedule[index] = auth_sha256_load_be32(block + (index * 4u));
    }

    for (size_t index = 16u; index < 64u; ++index) {
        schedule[index] = auth_sha256_small_sigma1(schedule[index - 2u]) +
                          schedule[index - 7u] +
                          auth_sha256_small_sigma0(schedule[index - 15u]) +
                          schedule[index - 16u];
    }

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    for (size_t index = 0; index < 64u; ++index) {
        const uint32_t temp1 = h + auth_sha256_big_sigma1(e) +
                               auth_sha256_choose(e, f, g) +
                               auth_sha256_round_constants[index] +
                               schedule[index];
        const uint32_t temp2 = auth_sha256_big_sigma0(a) +
                               auth_sha256_majority(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

void auth_sha256_init(auth_sha256_ctx_t *ctx)
{
    memcpy(ctx->state, auth_sha256_initial_state, sizeof(auth_sha256_initial_state));
    ctx->total_len = 0u;
    ctx->buffer_len = 0u;
    memset(ctx->buffer, 0, sizeof(ctx->buffer));
}

void auth_sha256_update(auth_sha256_ctx_t *ctx, const uint8_t *data, size_t length)
{
    size_t offset = 0u;

    if (length == 0u) {
        return;
    }

    ctx->total_len += (uint64_t)length;

    if (ctx->buffer_len > 0u) {
        /* Complete a previously buffered partial block before streaming full blocks. */
        const size_t buffer_space = AUTH_SHA256_BLOCK_BYTES - ctx->buffer_len;
        const size_t chunk = length < buffer_space ? length : buffer_space;

        memcpy(ctx->buffer + ctx->buffer_len, data, chunk);
        ctx->buffer_len += chunk;
        offset += chunk;

        if (ctx->buffer_len == AUTH_SHA256_BLOCK_BYTES) {
            auth_sha256_transform(ctx, ctx->buffer);
            ctx->buffer_len = 0u;
        }
    }

    while ((length - offset) >= AUTH_SHA256_BLOCK_BYTES) {
        auth_sha256_transform(ctx, data + offset);
        offset += AUTH_SHA256_BLOCK_BYTES;
    }

    if (offset < length) {
        const size_t remaining = length - offset;
        memcpy(ctx->buffer, data + offset, remaining);
        ctx->buffer_len = remaining;
    }
}

/**
 * @brief Finalize a SHA-256 message by appending padding and the bit length.
 */
void auth_sha256_finalize(auth_sha256_ctx_t *ctx,
                          uint8_t digest[AUTH_SHA256_DIGEST_BYTES])
{
    const uint64_t total_bits = ctx->total_len * 8u;

    ctx->buffer[ctx->buffer_len++] = 0x80u;

    if (ctx->buffer_len > 56u) {
        memset(ctx->buffer + ctx->buffer_len, 0,
               AUTH_SHA256_BLOCK_BYTES - ctx->buffer_len);
        auth_sha256_transform(ctx, ctx->buffer);
        ctx->buffer_len = 0u;
    }

    memset(ctx->buffer + ctx->buffer_len, 0, 56u - ctx->buffer_len);
    auth_sha256_store_be64(total_bits, ctx->buffer + 56u);
    auth_sha256_transform(ctx, ctx->buffer);

    for (size_t index = 0; index < 8u; ++index) {
        auth_sha256_store_be32(ctx->state[index], digest + (index * 4u));
    }

    ctx->buffer_len = 0u;
}

void auth_sha256_digest(const uint8_t *data,
                        size_t length,
                        uint8_t digest[AUTH_SHA256_DIGEST_BYTES])
{
    auth_sha256_ctx_t ctx;

    auth_sha256_init(&ctx);
    auth_sha256_update(&ctx, data, length);
    auth_sha256_finalize(&ctx, digest);
}
