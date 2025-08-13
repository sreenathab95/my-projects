#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
import pickle

# ------------------------------
# 1. Load Data
# ------------------------------
df = pd.read_csv("/home/gouri/Documents/jupiter/env/worksheets/my_work/diabetes_prediction_dataset.csv")  # Change to your dataset path

# ------------------------------
# 2. Encode Categorical Columns
# ------------------------------
label_encoders = {}
categorical_cols = df.select_dtypes(include=["object"]).columns

for col in categorical_cols:
    le = LabelEncoder()
    df[col] = le.fit_transform(df[col])
    label_encoders[col] = le

# Save the label encoders for later use in hosting
with open("label_encoders.pkl", "wb") as f:
    pickle.dump(label_encoders, f)

# ------------------------------
# 3. Train-Test Split
# ------------------------------
X = df.drop("diabetes", axis=1)  # Change "Outcome" to your target column
y = df["diabetes"]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# ------------------------------
# 4. Train Model
# ------------------------------
model = RandomForestClassifier(random_state=42)
model.fit(X_train, y_train)

# ------------------------------
# 5. Save Model
# ------------------------------
with open("diabetes_model.pkl", "wb") as f:
    pickle.dump(model, f)

print("✅ Model and encoders saved successfully!")


# In[2]:


import streamlit as st
import pandas as pd
import pickle

# ------------------------------
# Load model and encoders
# ------------------------------
with open("diabetes_model.pkl", "rb") as f:
    model = pickle.load(f)

with open("label_encoders.pkl", "rb") as f:
    label_encoders = pickle.load(f)

st.title("🩺 Diabetes Prediction App")
st.write("Enter patient details to predict diabetes (Yes/No).")

# ------------------------------
# Create form for user input
# ------------------------------
input_data = {}
for col in model.feature_names_in_:
    value = st.text_input(f"{col}:")
    input_data[col] = value

if st.button("Predict"):
    df = pd.DataFrame([input_data])

    # Apply same encoding as training
    for col, le in label_encoders.items():
        if col in df:
            df[col] = le.transform(df[col])

    # Convert numeric columns to float if needed
    for col in df.columns:
        try:
            df[col] = df[col].astype(float)
        except:
            pass

    prediction = model.predict(df)[0]
    prediction_label = "Yes" if prediction == 1 else "No"

    st.success(f"Prediction: **{prediction_label}**")


# In[ ]:




