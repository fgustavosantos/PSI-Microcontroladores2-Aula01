#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_LED0 500
#define SLEEP_TIME_LED1 250

// Define o LED usando Device Tree
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

// Verifica se o LED está definido no Device Tree
#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
#else
#error "Unsupported board: led0 devicetree alias is not defined"
#endif

#if DT_NODE_HAS_STATUS(LED1_NODE, okay)
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
#else
#error "Unsupported board: led0 devicetree alias is not defined"
#endif

#define STACK_SIZE 256
#define PRIORITY 7

void piscaLed0(void){
    while (1) {
        gpio_pin_toggle_dt(&led);
        k_msleep(SLEEP_TIME_LED0);
    }
}

void piscaLed1(void){
    while (1) {
        gpio_pin_toggle_dt(&led1);
        k_msleep(SLEEP_TIME_LED1);
    }
}

K_THREAD_DEFINE(toggle_led0, STACK_SIZE, piscaLed0, NULL, NULL, NULL, PRIORITY, 0, 0);
K_THREAD_DEFINE(toggle_led1, STACK_SIZE, piscaLed1, NULL, NULL, NULL, PRIORITY, 0, 0);

void main(void)
{
    int ret, ret1;

    // Verifica se o device está pronto
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED0 device %s is not ready\n", led.port->name);
        return;
    }
    if (!gpio_is_ready_dt(&led1)) {
        printk("Error: LED1 device %s is not ready\n", led1.port->name);
        return;
    }

    // Configura o pino como saída
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error %d: failed to configure LED0 pin\n", ret);
        return;
    }
    ret1 = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
    if (ret1 < 0) {
        printk("Error %d: failed to configure LED1 pin\n", ret1);
        return;
    }

    printk("LED0 blinking on %s pin %d\n", led.port->name, led.pin);
    printk("LED1 blinking on %s pin %d\n", led1.port->name, led1.pin);
}