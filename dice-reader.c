#include "../qmc5883l/qmc5883l.c"

/* Example usage for the qmc5883l library.
 * @return 1 if failure, 0 on success
 */
int main() {
  // init pico
  pico_init();

  // init qmc5883l
  bool success = qmc5883l_init();
  if (success) {
    printf("\ninit succeeded!!!\n");
  } else {
    printf("\ninit failed :(\n");
    return 1;
  }

  // Read data
  while (1) {
    int16_t x, y, z, t;
    qmc5883l_read_data(&x, &y, &z, &t);
    // Display
    printf("[%d, %d, %d] --- %d\n", x, y, z, t);
    sleep_ms(500);
  }
  return 0;
}
