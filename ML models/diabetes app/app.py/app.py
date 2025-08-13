import streamlit as st
import pandas as pd
import pickle
from pathlib import Path

# Load model & encoders
BASE_DIR = Path(__file__).parent

with open(BASE_DIR / "diabetes_model.pkl", "rb") as f:
    model = pickle.load(f)

with open(BASE_DIR / "label_encoders.pkl", "rb") as f:
    label_encoders = pickle.load(f)

st.set_page_config(page_title="🩺 Diabetes Prediction", page_icon="🩺")
st.title("🩺 Diabetes Prediction App")
st.write("Enter patient details to predict diabetes (Yes/No).")

# Input form
input_data = {}
for col in model.feature_names_in_:
    value = st.text_input(f"{col}:")
    input_data[col] = value

if st.button("Predict"):
    df = pd.DataFrame([input_data])

    # Apply encoding
    for col, le in label_encoders.items():
        if col in df:
            df[col] = le.transform(df[col])

    # Convert to numeric
    for col in df.columns:
        try:
            df[col] = df[col].astype(float)
        except:
            pass

    prediction = model.predict(df)[0]
    prediction_label = "Yes" if prediction == 1 else "No"
    st.success(f"Prediction: **{prediction_label}**")
