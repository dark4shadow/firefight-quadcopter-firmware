import json
import sys

def replay_logs(log_file):
    with open(log_file, 'r') as file:
        logs = json.load(file)
    
    for entry in logs:
        timestamp = entry.get('timestamp')
        action = entry.get('action')
        details = entry.get('details', {})
        
        print(f"[{timestamp}] Action: {action}, Details: {details}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python log_replayer.py <log_file>")
        sys.exit(1)

    log_file_path = sys.argv[1]
    replay_logs(log_file_path)