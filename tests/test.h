#ifndef C_TEST_H
#define C_TEST_H

int c_test_memory_placeholder(void);

int c_test_memory_small_buffer(void);
int c_test_memory_large_buffer(void);
int c_test_memory_null_zero_len(void);

int c_test_endian(void);
int c_test_endian_unaligned(void);

int c_test_ct_equal(void);
int c_test_ct_diff_start(void);
int c_test_ct_diff_middle(void);
int c_test_ct_diff_end(void);
int c_test_ct_empty(void);
int c_test_ct_single_byte_equal(void);
int c_test_ct_single_byte_diff(void);

int c_test_buf_add_no_overflow(void);
int c_test_buf_add_overflow(void);
int c_test_buf_mul_no_overflow(void);
int c_test_buf_mul_overflow(void);
int c_test_buf_validate_read_ok(void);
int c_test_buf_validate_read_null_zero(void);
int c_test_buf_validate_read_null_nonzero(void);
int c_test_buf_validate_write_ok(void);
int c_test_buf_validate_write_null_zero(void);
int c_test_buf_validate_write_null_nonzero(void);
int c_test_buf_validate_out_capacity_ok(void);
int c_test_buf_validate_out_capacity_small(void);
int c_test_buf_validate_out_capacity_null_len(void);
int c_test_buf_validate_out_capacity_null_out_zero(void);
int c_test_buf_validate_out_capacity_null_out_nonzero(void);

#endif 