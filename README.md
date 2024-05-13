## Explanation and Formulation for PID Controller in Discrete Time

In control systems, the PID (Proportional-Integral-Derivative) controller is a widely used feedback controller that adjusts the control signal based on the error between the desired setpoint and the current feedback value. The PID controller consists of three main components: proportional, integral, and derivative terms.

### Components of PID Controller:

1. **Proportional (P) Term**:
   - The proportional term adjusts the control signal proportionally to the current error. It provides immediate correction to the system's response based on the magnitude of the error.
   - The proportional control action is given by: \( K_p \times e[k] \), where \( K_p \) is the proportional gain and \( e[k] \) is the error at time step \( k \).

2. **Integral (I) Term**:
   - The integral term accumulates the error over time and eliminates steady-state error. It integrates the error signal to provide long-term correction to the system's response.
   - The integral control action is given by: \( K_i \times \sum_{i=0}^{k} e[i] \), where \( K_i \) is the integral gain and \( e[i] \) is the error at time step \( i \).

3. **Derivative (D) Term**:
   - The derivative term considers the rate of change of the error and improves the transient response of the system. It anticipates future error based on the current rate of change.
   - The derivative control action is given by: \( K_d \times (e[k] - e[k-1]) \), where \( K_d \) is the derivative gain, and \( e[k] \) and \( e[k-1] \) are the errors at time steps \( k \) and \( k-1 \) respectively.

### PID Controller Formulation:

The PID controller computes the control signal \( u[k] \) at each discrete time step \( k \) using the following formula:

\[ u[k] = K_p \times e[k] + K_i \times \sum_{i=0}^{k} e[i] + K_d \times (e[k] - e[k-1]) \]

where:
- \( K_p \), \( K_i \), and \( K_d \) are the proportional, integral, and derivative gains, respectively.
- \( e[k] \) represents the error at time step \( k \), calculated as the difference between the setpoint and the feedback value at time step \( k \).

### Control Signal Computation:

Once the PID controller computes the control signal \( u[k] \), it is applied to the system to drive it towards the setpoint. The control signal is typically applied for a fixed time step \( \Delta t \) to update the system's state or output. The updated system state or output is then used as feedback for the next iteration of the control loop.
