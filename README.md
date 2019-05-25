Image matching points finder based on RANSAC method, AI course at Wroclaw University of Science and Technology.
Implementation is done in C++ with QT lib serving as visualization tool.

Harris-Affine detector used with SIFT descriptor is used, which comes from University of Oxford Department of Egineering Science.
http://www.robots.ox.ac.uk/~vgg/research/affine/det_eval_files/extract_features2.tar.gz

For usage the following conditions must be met
  1. http://www.robots.ox.ac.uk/~vgg/research/affine/det_eval_files/extract_features2.tar.gz features extractor in unix version
     (extract_features_32bit.ln) must be present in folder "../features_extractor" relative to project root dir.
     
