# stm32-l432kc-pll-controller

An example of the application looks as following:

First you set up a Frequency with the signal generator (The PLL is programmed to have an initial frequency of $f = 50 \ \text{Hz}$ and a tolerance of 20%):

![IMG_2648](https://github.com/user-attachments/assets/4f03445c-d118-4ec8-be7b-5ac7c7a11fd1)

The PLL then begins estimating the current frequency, starting at $f = 50 \ \text{Hz}$.  In this example, the input frequency matches the initial frequency, so no significant changes are observed.
The OLED display output looks like this:

![IMG_2649](https://github.com/user-attachments/assets/0d897bf4-c5a5-456c-bf6d-97b259d604c5)

The connected encoder is used to set the phase at which a trigger signal should appear. In this case, a phase of 1° was configured. At a frequency of $f = 50 \ \text{Hz}$, 1° corresponds to approximately $55 \ \mu\text{s}$.
The image below shows the rising edge after pressing the button and reaching 1°:

![IMG_2650](https://github.com/user-attachments/assets/75de086d-7cb5-405b-bfd2-0c0392eb76c0)
