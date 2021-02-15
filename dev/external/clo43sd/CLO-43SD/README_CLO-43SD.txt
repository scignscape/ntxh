CLO-43SD
========

Created By
----------

Andrew Farnsworth, Michael Lanzone, Emma DeLeon, Lewis Grove, Bill Evans, 
Michael O’Brien and Justin Salamon.

Version 1.0


Description
-----------

The CLO-43SD dataset contains spectral representations of 5428 flight calls 
from 43 different species of North American wood-warblers (in the family 
Parulidae). The dataset can be used, amongst other things, for the research, 
development and testing of bioacoustic classification models, including the 
reproduction of the results reported in:


[1] J. Salamon, J. P. Bello, A. Farnsworth, M. Robbins, S. Keen, H. Klinck and 
    S. Kelling, “Towards the Automatic Classification of Avian Flight Calls for 
    Bioacoustic Monitoring”, submitted.


Data Files
----------

For each of the 5428 flight calls in this dataset, two forms of spectral 
representation are provided:

1. Log-mel spectrogram: extracted using the Essentia library 
(http://essentia.upf.edu/) using the following parameter values:
    - Window size: 11.6 ms (256 samples for sampling rate 22050 Hz)
    - Hop size: 1.45 ms (32 samples for sampling rate 22050 Hz)
    - Window type: Hann
    - Low frequency bound: 2000 Hz
    - High frequency bound: 11025
    - Number of mel bands: 40

2. Mel-Frequency Cepstral Coefficients (MFCC): extracted using the Essentia 
library (http://essentia.upf.edu/) using the following parameter values:
    - Window size: 11.6 ms (256 samples for sampling rate 22050 Hz)
    - Hop size: 1.45 ms (32 samples for sampling rate 22050 Hz)
    - Window type: Hann
    - Low frequency bound: 2000 Hz
    - High frequency bound: 11025
    - Number of mel bands: 40
    - number of MFCC coefficients: 25

The species of each call is indicated by the 4 letter code at the beginning of 
the filename (e.g. AMRE = American Redstart). A table mapping each 4 letter 
code to the full species name is provided as metadata (see Metadata Files).

All data files are provided in NPY format 
(http://docs.scipy.org/doc/numpy/neps/npy-format.html), which can be easily 
loaded into Python as follows:

import numpy as np
mfcc = np.load(‘AMRE_233054328_0101.mfcc.npy’)
logmelspec = np.load(‘AMRE_233054328_0101.logmelspec.npy’)

The dimensionality of mfcc will be: [n_frames, 25]
The dimensionality of logmelspec will be: [n_frames, 40]
Where n_frames will vary depending on the duration of each flight call.


Metadata Files
--------------

A single metadata file is provided in CSV format: CLO-43SD.csv
The file contains 3 columns:
    - Name: The full name of the species
    - Abbreviation: the 4 letter abbreviation code for the species
    - Instances: the number of times this species occurs in the dataset 


Please Acknowledge CLO-43SD in Academic Research
------------------------------------------------

When CLO-43SD is used for academic research, we request that scientific 
publications of works partly and wholly based on this dataset cite the 
following publication:

J. Salamon, J. P. Bello, A. Farnsworth, M. Robbins, S. Keen, H. Klinck and 
S. Kelling, “Towards the Automatic Classification of Avian Flight Calls for 
Bioacoustic Monitoring”, submitted.

The creation of this dataset was supported by NSF 1125098, the Laurel and 
Colcom Foundations, The University of Pittsburgh Honors College, Department of 
Defense Legacy Resource Management Program, a research assistantship from the 
Cornell Laboratory of Ornithology, and the Kieckhefer Adirondack Fellowship.


Conditions of Use
-----------------

Dataset created by Andrew Farnsworth, Michael Lanzone, Emma DeLeon, Lewis 
Grove, Bill Evans, Michael O’Brien and Justin Salamon.
 
The CLO-43SD dataset is offered free of charge under the terms of the Creative 
Commons CC0 1.0 Universal License: 
https://creativecommons.org/publicdomain/zero/1.0/
 
The dataset and its contents are made available on an "as is" basis and without 
warranties of any kind, including without limitation satisfactory quality and 
conformity, merchantability, fitness for a particular purpose, accuracy or 
completeness, or absence of errors. Subject to any liability that may not be 
excluded or limited by law, CLO is not liable for, and expressly excludes, all 
liability for loss or damage however and whenever caused to anyone by any use
of the CLO-43SD dataset or any part of it.


Feedback
--------

Please help us improve CLO-43SD by sending your feedback to: 
justin.salamon@gmail.com and af27@cornell.edu.

In case of a problem report please include as many details as possible.
