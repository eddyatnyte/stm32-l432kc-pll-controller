# stm32-l432kc-pll-controller

An example of the applications looks as following:

First you set up a Frequency with the signal generator (The PLL is programmed to have an initial frequency of 50Hz with a tolerance of 20%):

![IMG_2648](https://github.com/user-attachments/assets/4f03445c-d118-4ec8-be7b-5ac7c7a11fd1)

Then the PLL starts to estimate the current frequency starting of with $f = 50 \ \text{Hz}$. In this scenario the input frequency is the same as the initial frequency, so you might not notice changes.
The output of the OLED Display looks as following:

![IMG_2649](https://github.com/user-attachments/assets/0d897bf4-c5a5-456c-bf6d-97b259d604c5)

The connected Encoder is used to set up the phase at which a trigger Signal should appear. In this case, a phase of 1° was set. Regarding the frequency $f = 50 \ \text{Hz}$, 1° is equivalent to approxiamtely $55 \ \mu\text{s}$.
The following picture shows the rising edge after pressing the button and reaching 1°:

![IMG_2650](https://github.com/user-attachments/assets/75de086d-7cb5-405b-bfd2-0c0392eb76c0)
