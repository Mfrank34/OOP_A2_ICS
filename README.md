# Hospital Billing System

## Project Description
This C++ project is a **Hospital Billing System** that calculates a patient's total bill.  
The total is based on:
- Number of days stayed
- Surgery performed (optional)
- Medications administered (optional)

The system is divided into three main classes:
- `PatientAccount`
- `Surgery`
- `Pharmacy`
- `Tables`
- `FileManager`

---

## Classes Overview

### PatientAccount
- Tracks the number of days a patient stays in the hospital.
- Calculates the total bill.
- Daily room rate: **£200** per day.
- Adds surgery and medication charges to the bill.

### Surgery
- Holds a list of surgery types and their charges.
- Allows users to select a surgery.

| Surgery Type         | Charge (£) |
|----------------------|------------|
| Cataract Surgery      | 1500       |
| Debridement           | 180        |
| Low Back Pain Surgery | 900        |
| Tonsillectomy         | 2100       |

### Pharmacy
- Holds a list of medication types and their prices.
- Allows users to select a medication.

| Medication Type    | Price (£) |
|--------------------|-----------|
| Antibiotic         | 20        |
| Anti-inflammatory  | 17        |
| Anti-nausea        | 38        |
| Inhalant           | 66        |
| Pain Relief        | 35        |

---

##  How to Compile and Run

1. Open a terminal.
2. Navigate to the project folder.
3. Compile the project:
   ```bash
   g++ -o HospitalBilling main.cpp PatientAccount.cpp Surgery.cpp Pharmacy.cpp
