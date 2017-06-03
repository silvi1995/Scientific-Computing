function coeff = FileParse(FileName);
fid = fopen(FileName);

tline = fgetl(fid);
coefficient = zeros(1,4);
index = 0;

while ischar(tline)
  index = index + 1;
  input = strsplit(tline,' ')
  coefficient(index,1) = input(1,1);
  coefficient(index,2) = input(1,2);
  coefficient(index,3) = input(1,3);
  coefficient(index,4) = input(1,4);
  tline = fgetl(fid);
end
coeff = coefficient;
end