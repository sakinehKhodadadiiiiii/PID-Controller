#include <iostream>

// Define the PIDController class
class PIDController {
private:
    // Define private members
    double kp; // Proportional gain
    double ki; // Integral gain
    double kd; // Derivative gain
    double integral; // Integral term
    double prev_error; // Previous error

public:
    // Constructor
    PIDController(double proportional_gain, double integral_gain, double derivative_gain)
        : kp(proportional_gain), ki(integral_gain), kd(derivative_gain), integral(0.0), prev_error(0.0) {}

    // Method to compute control signal
    double computeControlSignal(double error, double dt) {
        // Compute proportional term
        double proportional_term = kp * error;

        // Compute integral term (with anti-windup)
        integral += error * dt;
        double integral_term = ki * integral;

        // Compute derivative term
        double derivative_term = kd * (error - prev_error) / dt;

        // Compute control signal
        double control_signal = proportional_term + integral_term + derivative_term;

        // Update previous error for next iteration
        prev_error = error;

        return control_signal;
    }
};

int main() {
    // Define PID controller gains
    double kp = 1.0;
    double ki = 0.1;
    double kd = 0.01;

    // Create PID controller object
    PIDController pid_controller(kp, ki, kd);

    // Simulate control loop
    double target_value = 100.0;
    double current_value = 0.0;
    double dt = 0.01; // Time step
    double total_time = 10.0; // Total simulation time
    double time = 0.0;

    while (time < total_time) {
        // Compute error
        double error = target_value - current_value;

        // Compute control signal
        double control_signal = pid_controller.computeControlSignal(error, dt);

        // Apply control signal (simulate system response)
        // Here, we assume the system response is instantaneous
        current_value += control_signal * dt;

        // Print current value and control signal
        std::cout << "Time: " << time << " | Current Value: " << current_value << " | Control Signal: " << control_signal << std::endl;

        // Increment time
        time += dt;
    }

    return 0;
}
