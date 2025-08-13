import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
import pickle
from pathlib import Path

# Path to dataset (keep in same folder for easy hosting)
DATA_PATH = Path("diabetes_prediction_dataset.csv")

# Load Data
df = pd.read_csv(DATA_PATH)

# Encode categorical columns
label_encoders = {}
categorical_cols = df.select_dtypes(include=["object"]).columns

for col in categorical_cols:
    le = LabelEncoder()
    df[col] = le.fit_transform(df[col])
    label_encoders[col] = le

# Save encoders
with open("label_encoders.pkl", "wb") as f:
    pickle.dump(label_encoders, f)

# Train-Test Split
X = df.drop("diabetes", axis=1)
y = df["diabetes"]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train Model
model = RandomForestClassifier(random_state=42)
model.fit(X_train, y_train)

# Save Model
with open("diabetes_model.pkl", "wb") as f:
    pickle.dump(model, f)

print("✅ Model and encoders saved successfully!")
