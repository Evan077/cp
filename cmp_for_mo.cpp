struct qr{
  ll l,r,in;
//l and r are query range and in is thee index of the query;
};
bool cmp(qr q1,qr q2){
   if(q1.l/block!=q2.l/block) return q1.l/block<q2.l/block;
   return q1.r<q2.r;
}
