# PID Controller in Discrete Time

The PID (Proportional-Integral-Derivative) controller adjusts the control signal based on the error between the desired setpoint and the current feedback value. It consists of three main components:

- **Proportional (P) Term**: \( K_p \times e[k] \)
- **Integral (I) Term**: \( K_i \times \sum_{i=0}^{k} e[i] \)
- **Derivative (D) Term**: \( K_d \times (e[k] - e[k-1]) \)

## PID Controller Formula

The control signal \( u[k] \) computed by the PID controller is given by the following formula:

\[ u[k] = K_p \times e[k] + K_i \times \sum_{i=0}^{k} e[i] + K_d \times (e[k] - e[k-1]) \]

The control signal is applied to the system to drive it towards the setpoint.
