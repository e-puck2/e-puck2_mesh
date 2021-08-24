/* Mesh Internal Communication Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <string.h>
#include "esp_err.h"
#include "esp_mesh.h"
#include "mesh_light.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "rgb_led_e-puck2.h"

/*******************************************************
 *                Constants
 *******************************************************/
/* RGB configuration on ESP-WROVER-KIT board */
#define LEDC_IO_0    (0)
#define LEDC_IO_1    (2)
#define LEDC_IO_2    (4)
#define LEDC_IO_3    (5)

/*******************************************************
 *                Variable Definitions
 *******************************************************/
static bool s_light_inited = false;

/*******************************************************
 *                Function Definitions
 *******************************************************/
esp_err_t mesh_light_init(void)
{
    if (s_light_inited == true) {
        return ESP_OK;
    }
    s_light_inited = true;

    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT,
        .freq_hz = 5000,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .channel = LEDC_CHANNEL_0,
        .duty = 100,
        .gpio_num = LEDC_IO_0,
        .intr_type = LEDC_INTR_FADE_END,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_sel = LEDC_TIMER_0
    };
    ledc_channel_config(&ledc_channel);
    ledc_channel.channel = LEDC_CHANNEL_1;
    ledc_channel.gpio_num = LEDC_IO_1;
    ledc_channel_config(&ledc_channel);
    ledc_channel.channel = LEDC_CHANNEL_2;
    ledc_channel.gpio_num = LEDC_IO_2;
    ledc_channel_config(&ledc_channel);
    ledc_channel.channel = LEDC_CHANNEL_3;
    ledc_channel.gpio_num = LEDC_IO_3;
    ledc_channel_config(&ledc_channel);
    ledc_fade_func_install(0);

    mesh_light_set(MESH_LIGHT_INIT);
    return ESP_OK;
}

esp_err_t mesh_light_set(int color)
{
    switch (color) {
    case MESH_LIGHT_RED:	
        /* Red */
		rgb_set_intensity(LED2, RED_LED, 100, 50);
		rgb_set_intensity(LED2, BLUE_LED, 0, 50);
		rgb_set_intensity(LED2, GREEN_LED, 0, 50);
		rgb_set_intensity(LED4, RED_LED, 100, 50);
		rgb_set_intensity(LED4, BLUE_LED, 0, 50);
		rgb_set_intensity(LED4, GREEN_LED, 0, 50);
		rgb_set_intensity(LED6, RED_LED, 100, 50);
		rgb_set_intensity(LED6, BLUE_LED, 0, 50);
		rgb_set_intensity(LED6, GREEN_LED, 0, 50);
		rgb_set_intensity(LED8, RED_LED, 100, 50);
		rgb_set_intensity(LED8, BLUE_LED, 0, 50);
		rgb_set_intensity(LED8, GREEN_LED, 0, 50);
        break;
    case MESH_LIGHT_GREEN:
        /* Green */
		rgb_set_intensity(LED2, RED_LED, 0, 50);
		rgb_set_intensity(LED2, BLUE_LED, 0, 50);
		rgb_set_intensity(LED2, GREEN_LED, 100, 50);
		rgb_set_intensity(LED4, RED_LED, 0, 50);
		rgb_set_intensity(LED4, BLUE_LED, 0, 50);
		rgb_set_intensity(LED4, GREEN_LED, 100, 50);
		rgb_set_intensity(LED6, RED_LED, 0, 50);
		rgb_set_intensity(LED6, BLUE_LED, 0, 50);
		rgb_set_intensity(LED6, GREEN_LED, 100, 50);
		rgb_set_intensity(LED8, RED_LED, 0, 50);
		rgb_set_intensity(LED8, BLUE_LED, 0, 50);
		rgb_set_intensity(LED8, GREEN_LED, 100, 50);		
        break;
    case MESH_LIGHT_BLUE:
        /* Blue */
		rgb_set_intensity(LED2, RED_LED, 0, 50);
		rgb_set_intensity(LED2, BLUE_LED, 100, 50);
		rgb_set_intensity(LED2, GREEN_LED, 0, 50);
		rgb_set_intensity(LED4, RED_LED, 0, 50);
		rgb_set_intensity(LED4, BLUE_LED, 100, 50);
		rgb_set_intensity(LED4, GREEN_LED, 0, 50);
		rgb_set_intensity(LED6, RED_LED, 0, 50);
		rgb_set_intensity(LED6, BLUE_LED, 100, 50);
		rgb_set_intensity(LED6, GREEN_LED, 0, 50);
		rgb_set_intensity(LED8, RED_LED, 0, 50);
		rgb_set_intensity(LED8, BLUE_LED, 100, 50);
		rgb_set_intensity(LED8, GREEN_LED, 0, 50);			
        break;
    case MESH_LIGHT_YELLOW:
        /* Yellow */
		rgb_set_intensity(LED2, RED_LED, 100, 50);
		rgb_set_intensity(LED2, BLUE_LED, 0, 50);
		rgb_set_intensity(LED2, GREEN_LED, 100, 50);
		rgb_set_intensity(LED4, RED_LED, 100, 50);
		rgb_set_intensity(LED4, BLUE_LED, 0, 50);
		rgb_set_intensity(LED4, GREEN_LED, 100, 50);
		rgb_set_intensity(LED6, RED_LED, 100, 50);
		rgb_set_intensity(LED6, BLUE_LED, 0, 50);
		rgb_set_intensity(LED6, GREEN_LED, 100, 50);
		rgb_set_intensity(LED8, RED_LED, 100, 50);
		rgb_set_intensity(LED8, BLUE_LED, 0, 50);
		rgb_set_intensity(LED8, GREEN_LED, 100, 50);	
        break;
    case MESH_LIGHT_PINK:
        /* Pink */
		rgb_set_intensity(LED2, RED_LED, 100, 50);
		rgb_set_intensity(LED2, BLUE_LED, 100, 50);
		rgb_set_intensity(LED2, GREEN_LED, 0, 50);
		rgb_set_intensity(LED4, RED_LED, 100, 50);
		rgb_set_intensity(LED4, BLUE_LED, 100, 50);
		rgb_set_intensity(LED4, GREEN_LED, 0, 50);
		rgb_set_intensity(LED6, RED_LED, 100, 50);
		rgb_set_intensity(LED6, BLUE_LED, 100, 50);
		rgb_set_intensity(LED6, GREEN_LED, 0, 50);
		rgb_set_intensity(LED8, RED_LED, 100, 50);
		rgb_set_intensity(LED8, BLUE_LED, 100, 50);
		rgb_set_intensity(LED8, GREEN_LED, 0, 50);
        break;
    case MESH_LIGHT_INIT:
        /* can't say */
		rgb_set_intensity(LED2, RED_LED, 0, 50);
		rgb_set_intensity(LED2, BLUE_LED, 100, 50);
		rgb_set_intensity(LED2, GREEN_LED, 100, 50);
		rgb_set_intensity(LED4, RED_LED, 0, 50);
		rgb_set_intensity(LED4, BLUE_LED, 100, 50);
		rgb_set_intensity(LED4, GREEN_LED, 100, 50);
		rgb_set_intensity(LED6, RED_LED, 0, 50);
		rgb_set_intensity(LED6, BLUE_LED, 100, 50);
		rgb_set_intensity(LED6, GREEN_LED, 100, 50);
		rgb_set_intensity(LED8, RED_LED, 0, 50);
		rgb_set_intensity(LED8, BLUE_LED, 100, 50);
		rgb_set_intensity(LED8, GREEN_LED, 100, 50);
        break;
    case MESH_LIGHT_WARNING:
        /* warning */
		rgb_set_intensity(LED2, RED_LED, 100, 50);
		rgb_set_intensity(LED2, BLUE_LED, 100, 50);
		rgb_set_intensity(LED2, GREEN_LED, 100, 50);
		rgb_set_intensity(LED4, RED_LED, 100, 50);
		rgb_set_intensity(LED4, BLUE_LED, 100, 50);
		rgb_set_intensity(LED4, GREEN_LED, 100, 50);
		rgb_set_intensity(LED6, RED_LED, 100, 50);
		rgb_set_intensity(LED6, BLUE_LED, 100, 50);
		rgb_set_intensity(LED6, GREEN_LED, 100, 50);
		rgb_set_intensity(LED8, RED_LED, 100, 50);
		rgb_set_intensity(LED8, BLUE_LED, 100, 50);
		rgb_set_intensity(LED8, GREEN_LED, 100, 50);
        break;
    default:
        /* off */
		rgb_set_intensity(LED2, RED_LED, 0, 50);
		rgb_set_intensity(LED2, BLUE_LED, 0, 50);
		rgb_set_intensity(LED2, GREEN_LED, 0, 50);
		rgb_set_intensity(LED4, RED_LED, 0, 50);
		rgb_set_intensity(LED4, BLUE_LED, 0, 50);
		rgb_set_intensity(LED4, GREEN_LED, 0, 50);
		rgb_set_intensity(LED6, RED_LED, 0, 50);
		rgb_set_intensity(LED6, BLUE_LED, 0, 50);
		rgb_set_intensity(LED6, GREEN_LED, 0, 50);
		rgb_set_intensity(LED8, RED_LED, 0, 50);
		rgb_set_intensity(LED8, BLUE_LED, 0, 50);
		rgb_set_intensity(LED8, GREEN_LED, 0, 50);
    }

    return ESP_OK;
}

void mesh_connected_indicator(int layer)
{
    switch (layer) {
    case 1:
        mesh_light_set(MESH_LIGHT_PINK);
        break;
    case 2:
        mesh_light_set(MESH_LIGHT_YELLOW);
        break;
    case 3:
        mesh_light_set(MESH_LIGHT_RED);
        break;
    case 4:
        mesh_light_set(MESH_LIGHT_BLUE);
        break;
    case 5:
        mesh_light_set(MESH_LIGHT_GREEN);
        break;
    case 6:
        mesh_light_set(MESH_LIGHT_WARNING);
        break;
    default:
        mesh_light_set(0);
    }
}

void mesh_disconnected_indicator(void)
{
    mesh_light_set(MESH_LIGHT_WARNING);
}

esp_err_t mesh_light_process(mesh_addr_t *from, uint8_t *buf, uint16_t len)
{
    mesh_light_ctl_t *in = (mesh_light_ctl_t *) buf;
    if (!from || !buf || len < sizeof(mesh_light_ctl_t)) {
        return ESP_FAIL;
    }
    if (in->token_id != MESH_TOKEN_ID || in->token_value != MESH_TOKEN_VALUE) {
        return ESP_FAIL;
    }
    if (in->cmd == MESH_CONTROL_CMD) {
        if (in->on) {
            mesh_connected_indicator(esp_mesh_get_layer());
        } else {
            mesh_light_set(0);
        }
    }
    return ESP_OK;
}
