#!/usr/bin/env python
# coding: utf-8

# dataset was downloaded from : www.kaggle.com

# In[1]:


import pandas as pd
import numpy as np

dia = pd.read_csv("/home/gouri/Documents/jupiter/env/worksheets/my_work/diabetes_prediction_dataset.csv")
dia.head()


# In[2]:


dia.info()


# In[3]:


dia.shape


# In[4]:


dia.diabetes.value_counts()


# In[ ]:





# In[5]:


# 2 categorical variable and rest are numerical variable


# In[6]:


#making categorical variable and numerical varibale in 2 seperate group


# In[7]:


cat_var = dia.select_dtypes(include=['object']).columns
num_var = dia.select_dtypes(include = np.number).columns.tolist()
num_var,cat_var


# ### univariate analysis

# In[8]:


import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')
import seaborn as sn

for col in num_var:
    print(col)
    print('skew: ',round(dia[col].skew(),2))
    plt.figure(figsize=(8,5))
    plt.subplot(3,2,1)
    dia[col].hist(grid=False,bins=50)
    plt.ylabel('count')
    plt.xlabel(col)
    plt.subplot(3,2,2)
    sn.boxplot(dia[col])
    plt.show()


# AGE:
# 
# here more people are 80 or above 80 yrs old
# 
# HYPERTENSION AND HEART DISEASES:
# 
# For majourity of people there is no hypertension or heart diseases
# 
# BMI:
# 
# BMI refres to Body Mass Index. BMI>25 is considered as overweighted
# here majourity of peoplr are over weighted.
# 
# HbA1c_level: 
# 
# HbA1c_level refers to average blood glucose levels for last 2 or 3 months.
# HbA1c_level>6.5% is considered as diabetes
# 
# Blood_glucose_level:
# 
# most of the pepole have blood sugar greater than 125.
# 
# 
# Diabetes:
# 
# most of the pople don't have diabetes.

# In[9]:


#checking categorical variable


# In[10]:


fig,axes = plt.subplots(1,2,figsize=(8,2))
sn.countplot(data=dia,x='gender',order=dia['gender'].value_counts().index,ax=axes[0])
sn.countplot(data=dia,x='smoking_history',order = dia['smoking_history'].value_counts().index,ax=axes[1])
axes[1].tick_params(labelrotation=30)

plt.show()


# 

# In[11]:


dia.drop(['hypertension','heart_disease','smoking_history'],axis='columns',inplace=True)


# In[12]:


plt.figure(figsize=(12,7))
sn.heatmap(dia.corr(),annot=True)


# In[13]:


dia.describe()


# In[14]:


#the age columns have outliners removing the outliners.


# removing the ages less than 0.1, 0.1 means 1 month

# In[15]:


dia = dia[dia.age>0.1]


# In[16]:


dia.shape


# In[17]:


dia = pd.concat([dia,pd.get_dummies(dia.gender,drop_first=True)],axis='columns')
dia.drop(['gender'],axis='columns',inplace=True)
dia.head()


# In[18]:


x = dia.drop(['diabetes'],axis='columns')
y = dia['diabetes']


from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test = train_test_split(x,y,train_size=0.8,random_state=200,stratify=dia['diabetes'])


# In[19]:


from imblearn.over_sampling import SMOTE
smote = SMOTE(sampling_strategy='minority')
x_train,y_train = smote.fit_resample(x_train,y_train)


# In[20]:


from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import cross_val_score


# In[21]:


model = DecisionTreeClassifier()
model.fit(x_train,y_train)
model.score(x_test,y_test),model.score(x_train,y_train)


# In[22]:


model_2 = RandomForestClassifier()
model_2.fit(x_train,y_train)
model_2.score(x_test,y_test),model_2.score(x_train,y_train)


# In[23]:


#y_predicted = model.predict(x_test)

y_predicted_2 = model_2.predict(x_test)


# In[24]:


from sklearn.metrics import f1_score, roc_auc_score
#y_prob = model.predict_proba(x_test)[:,-1]
y_prob_2 = model_2.predict_proba(x_test)[:,-1]
for t in [0.3, 0.4, 0.5, 0.6, 0.7,0.8,0.9]:
    y_predicted_2 = (y_prob_2 > t).astype(int)
    print(f"Threshold={t} → F1 Score: {f1_score(y_test, y_predicted_2):.4f}")


# #### computing F1 score

# In[25]:


#score_1 = f1_score(y_test,y_predicted)
#print("f1_score : ", score_1)

score_2 = f1_score(y_test,y_predicted_2)
print("f1_score_2 : ",score_2)


# #### computing AUC score
# 
# 

# In[26]:


auc = roc_auc_score(y_test, y_prob_2)
print("AUC Score:", auc)


# In[ ]:




