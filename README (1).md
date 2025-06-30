
# Option Pricing Engine (C++ and Python)

This project is a real-time option pricing tool built with a C++ core for performance and a Python interface for usability. It prices European call and put options using the Black-Scholes model and fetches live market data through Yahoo Finance. The system runs in Google Colab and allows users to input variables and visualize the resulting price and payoff.

## What It Does

- Implements the Black-Scholes model to price options based on real market inputs.
- Uses a C++ back end for fast, precise calculation.
- Exposes the engine through Python using `subprocess`, so users can control it from Colab.
- Fetches live stock and option data from Yahoo Finance (`yfinance`).
- Offers an interactive UI using `ipywidgets` and visualizes the option payoff at expiry.

## Core Technology Overview

- C++ handles the mathematical computation of option prices.
- Google Colab serves as a front-end for inputs and results.
- `clang++` / `g++` compile the C++ source files into a machine-readable program.
- Terminal + `chmod` give execution permissions to the compiled file inside Colab (Linux-based).
- Python (`subprocess.run`) sends user inputs to the C++ engine and returns the result.

## Financial and Mathematical Logic

### Black-Scholes Model

The Black-Scholes formula predicts how much an option is worth based on:

- The current stock price  
- The strike price of the option  
- How long until it expires  
- Volatility (how much the stock moves)  
- Interest rates

It estimates the probability that the option will end up profitable, adjusted for time and risk.

### The Greeks (Optional)

Greeks measure how sensitive the option's price is to different market factors:

- Delta: How much the option price changes when the stock price changes.
- Gamma: How fast Delta itself changes.
- Theta: How much value the option loses with time (time decay).
- Vega: Sensitivity to volatility.
- Rho: Sensitivity to interest rate changes.

Traders use Greeks to manage risk and hedge positions.

## How to Use It

1. Open `pricing_engine.ipynb` in Google Colab  
2. Upload the `.cpp` and `.hpp` files from this repo  
3. Run the notebook from top to bottom:
   - Compile the C++ code with `g++`
   - Enable execution with `chmod`
   - Enter your option inputs via the interactive UI
   - Click "Calculate" to view the price and payoff chart

## Files Included

- `main.cpp` – handles input/output and execution
- `black_scholes.cpp / .hpp` – pricing logic
- `greeks.cpp / .hpp` – Greek calculations
- `binomial_tree.cpp / .hpp` – optional binomial method (not used in UI)
- `pricing_engine.ipynb` – interactive notebook
- `README.md` – this file
