import subprocess

def run_pricing_engine(S, K, r, T, sigma, option_type="call"):
    cmd = ['./pricing_engine', str(S), str(K), str(r), str(T), str(sigma), option_type]
    result = subprocess.run(cmd, capture_output=True, text=True)
    print(result.stdout)

# Example usage
run_pricing_engine(192.3, 200, 0.05, 0.3, 0.25, "call")
