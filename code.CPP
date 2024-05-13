#include <iostream>
#include <vector>

class PIDController {
private:
    double kp; // Proportional gain
    double ki; // Integral gain
    double kd; // Derivative gain
    double prevError; // Previous error
    double integral; // Integral of errors

public:
    // Constructor
    PIDController(double p, double i, double d)
        : kp(p), ki(i), kd(d), prevError(0), integral(0) {}

    // Compute control signal
    double compute(double setpoint, double feedback, double dt) {
        // Calculate error
        double error = setpoint - feedback;
        integral += error * dt;

        // Proportional term
        double proportionalTerm = kp * error;

        // Integral term
        double integralTerm = ki * integral;

        // Derivative term
        double derivativeTerm = kd * (error - prevError) / dt;

        // Update previous error
        prevError = error;

        // Compute control signal
        double controlSignal = proportionalTerm + integralTerm + derivativeTerm;

        return controlSignal;
    }
};

int main() {
    // PID gains
    double kp = 0.5;
    double ki = 0.2;
    double kd = 0.1;

    // Setpoint and initial feedback
    double setpoint = 10.0;
    double feedback = 0.0;

    // Time parameters
    double dt = 0.01; // Time step
    double total_time = 10.0; // Total simulation time

    // Create PID controller object
    PIDController pid(kp, ki, kd);

    // Simulate PID control loop and write data to file
    for (double t = 0; t <= total_time; t += dt) {
        // Compute control signal
        double controlSignal = pid.compute(setpoint, feedback, dt);

        // Apply control signal to the system (simulate)
        feedback += controlSignal * dt;

        // Write time and feedback to file
        std::cout << t << " " << feedback << std::endl;
    }

    return 0;
}
