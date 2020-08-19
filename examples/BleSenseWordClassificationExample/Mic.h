/**
 * Adapted from https://github.com/DaleGia/nano-33-sense-serial-example
 */

#include <PDM.h>
#include <arm_math.h>

#define MICROPHONE_BUFFER_SIZE_IN_WORDS (256U)
#define MICROPHONE_BUFFER_SIZE_IN_BYTES (MICROPHONE_BUFFER_SIZE_IN_WORDS * sizeof(int16_t))


/**
 * Simple access to Ble Sense mic
 */
class Mic {
public:

    /**
     * Constructor
     */
    Mic() :
            _ready(false) {

    }

    /**
     * Setup PDM library
     */
    bool begin(uint8_t gain = 20) {
        PDM.begin(1, 16000);
        PDM.setGain(gain);
    }

    /**
     * Test if mic has new data
     */
    bool hasData() {
        return _ready;
    }

    /**
     * Get the RMS value
     */
    int16_t data() {
        return _rms;
    }

    /**
     *
     * @return
     */
    int16_t pop() {
        int16_t rms = data();

        reset();

        return rms;
    }

    /**
     * Read the audio data from the PDM object
     */
    void update() {
        int bytesAvailable = PDM.available();

        if(bytesAvailable == MICROPHONE_BUFFER_SIZE_IN_BYTES) {
            int16_t _buffer[MICROPHONE_BUFFER_SIZE_IN_WORDS];

            _ready = true;
            PDM.read(_buffer, bytesAvailable);
            arm_rms_q15((q15_t*)_buffer, MICROPHONE_BUFFER_SIZE_IN_WORDS, (q15_t*)&_rms);
        }
    }

    /**
     * Mark data as read
     */
    void reset() {
        _ready = false;
    }


protected:
    int16_t _rms;
    bool _ready;
};