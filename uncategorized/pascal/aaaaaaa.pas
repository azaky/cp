var
  n1,n2,n3,n4,n5,max,min,sum,i:integer;
  stat:array[35..125] of boolean;

begin
  for i:=35 to 125 do stat[i]:=false;
  max:=0;
  min:=0;
  for n1:=1 to 9 do
    for n2:=1 to 9 do
      for n3:=1 to 9 do
        for n4:=1 to 9 do
          for n5:=1 to 9 do
            if (n1<>n2) and
               (n1<>n3) and
               (n1<>n4) and
               (n1<>n5) and
               (n2<>n3) and
               (n2<>n4) and
               (n2<>n5) and
               (n3<>n4) and
               (n3<>n5) and
               (n4<>n5) then
            begin
              sum:=n1+4*n2+6*n3+4*n4+n5;
              if max = 0 then max:=sum
                else if sum>max then max:=sum;
              if min = 0 then min:=sum
                else if sum<min then min:=sum;
              stat[sum]:=true;
            end;
  for i:=35 to 125 do if (stat[i]) then writeln(i);
end.
