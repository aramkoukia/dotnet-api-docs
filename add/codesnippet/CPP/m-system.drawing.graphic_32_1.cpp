public:
   void IntersectClipRectangle( PaintEventArgs^ e )
   {
      // Set clipping region.
      Rectangle clipRect = Rectangle(0,0,200,200);
      e->Graphics->SetClip( clipRect );

      // Update clipping region to intersection of
      // existing region with specified rectangle.
      Rectangle intersectRect = Rectangle(100,100,200,200);
      e->Graphics->IntersectClip( intersectRect );

      // Fill rectangle to demonstrate effective clipping region.
      e->Graphics->FillRectangle( gcnew SolidBrush( Color::Blue ), 0, 0, 500, 500 );

      // Reset clipping region to infinite.
      e->Graphics->ResetClip();

      // Draw clipRect and intersectRect to screen.
      e->Graphics->DrawRectangle( gcnew Pen( Color::Black ), clipRect );
      e->Graphics->DrawRectangle( gcnew Pen( Color::Red ), intersectRect );
   }