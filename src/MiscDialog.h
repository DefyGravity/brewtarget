/*
 * MiscDialog.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009-2012.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MISCDIALOG_H
#define   _MISCDIALOG_H

class MiscDialog;

#include <QWidget>
#include <QDialog>
#include <QVariant>
#include "ui_miscDialog.h"
#include "database.h"

// Forward declarations.
class MainWindow;
class MiscEditor;
class MiscTableModel;
class MiscSortFilterProxyModel;

/*!
 * \class MiscDialog
 * \author Philip G. Lee
 *
 * \brief View/controller dialog for the miscs in the database.
 */
class MiscDialog : public QDialog, public Ui::miscDialog
{
   Q_OBJECT

public:
   MiscDialog(MainWindow* parent);
   virtual ~MiscDialog() {}

public slots:
   //! Add the selected misc to the current recipe.
   void addMisc(const QModelIndex& = QModelIndex());
   //! Delete selected misc from the database.
   void removeMisc();
   //! Bring up the editor for the selected misc.
   void editSelected();
   //! Add a new misc to the database.
   void newMisc();

   void changed(QMetaProperty prop, QVariant val);
   
private:
   MainWindow* mainWindow;
   MiscTableModel* miscTableModel;
   MiscSortFilterProxyModel* miscTableProxy;
   int numMiscs;
   MiscEditor* miscEdit;

   void populateTable();
};

#endif   /* _MISCDIALOG_H */

