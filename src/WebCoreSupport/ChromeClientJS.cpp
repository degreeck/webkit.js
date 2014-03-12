/* Licensed under BSD style license.
 * (c) 2014 True Interactions
 */
#include "config.h"
#include "FloatRect.h"
#include <emscripten.h>
#include "DebuggerJS.h"
#include "ChromeClientJS.h"

using namespace WebCore;

namespace WebCore {


  //static PassOwnPtr<WidgetBackingStore> createBackingStore(GtkWidget* widget, const IntSize& size)
  //{
  //  return WebCore::WidgetBackingStoreCairo::create(widget, size);
  //}

  ChromeClient* ChromeClientJS::createClient() {
    webkitTrace();
    ChromeClient* tmp = static_cast<ChromeClient *>(new ChromeClientJS());
		tmp->setWindowRect(FloatRect(0,0,1024,768)); // TODO: Set this through JS?
		return tmp;
  }

  ChromeClientJS::ChromeClientJS()
  {
    notImplemented();
  }
  void ChromeClientJS::chromeDestroyed()
  {
    webkitTrace();
    delete this;
  }

  FloatRect ChromeClientJS::windowRect()
  {
    webkitTrace();
    return m_pageRect;
    
  }

  void ChromeClientJS::setWindowRect(const FloatRect& rect)
  {
    webkitTrace();
    m_pageRect = rect;
  }

  FloatRect ChromeClientJS::pageRect()
  {
    webkitTrace();
    return m_pageRect;
  }

  void ChromeClientJS::focus()
  {
    webkitTrace();
  }

  void ChromeClientJS::unfocus()
  {
    webkitTrace();
  }

  Page* ChromeClientJS::createWindow(Frame* frame, const FrameLoadRequest& frameLoadRequest, const WindowFeatures& coreFeatures, const NavigationAction&)
  {
    webkitTrace();
    return 0;
  }

  void ChromeClientJS::show()
  {
    webkitTrace();
  }

  bool ChromeClientJS::canRunModal()
  {
    webkitTrace();
    return false;
  }

  void ChromeClientJS::runModal()
  {
    webkitTrace();
    notImplemented();
  }

  void ChromeClientJS::setToolbarsVisible(bool visible)
  {
    webkitTrace();
  }

  bool ChromeClientJS::toolbarsVisible()
  {
    webkitTrace();
    return false;
  }

  void ChromeClientJS::setStatusbarVisible(bool visible)
  {
    webkitTrace();
  }

  bool ChromeClientJS::statusbarVisible()
  {
    webkitTrace();
    return false;
  }

  void ChromeClientJS::setScrollbarsVisible(bool visible)
  {
    webkitTrace();
  }

  bool ChromeClientJS::scrollbarsVisible()
  {
    webkitTrace();
    return false;
  }

  void ChromeClientJS::setMenubarVisible(bool visible)
  {
    webkitTrace();
  }

  bool ChromeClientJS::menubarVisible()
  {
    webkitTrace();
    return false;
  }

  void ChromeClientJS::setResizable(bool)
  {
    webkitTrace();
  }

  void ChromeClientJS::closeWindowSoon()
  {
    webkitTrace();
  }

  bool ChromeClientJS::canTakeFocus(FocusDirection)
  {
    webkitTrace();
    return true;
  }

  void ChromeClientJS::takeFocus(FocusDirection)
  {
    webkitTrace();
  }

  void ChromeClientJS::focusedElementChanged(Element*)
  {
    webkitTrace();
  }

  void ChromeClientJS::focusedFrameChanged(Frame*)
  {
    webkitTrace();
  }

  bool ChromeClientJS::canRunBeforeUnloadConfirmPanel()
  {
    webkitTrace();
    return true;
  }

  bool ChromeClientJS::runBeforeUnloadConfirmPanel(const WTF::String& message, WebCore::Frame* frame)
  {
    webkitTrace();
    return true;
  }

  void ChromeClientJS::addMessageToConsole(WebCore::MessageSource source, WebCore::MessageLevel level, const WTF::String& message, unsigned lineNumber, unsigned columnNumber, const WTF::String& sourceId)
  {
    webkitTrace();
  }

  void ChromeClientJS::runJavaScriptAlert(Frame* frame, const String& message)
  {
    webkitTrace();
  }

  bool ChromeClientJS::runJavaScriptConfirm(Frame* frame, const String& message)
  {
    webkitTrace();
    return true;
  }

  bool ChromeClientJS::runJavaScriptPrompt(Frame* frame, const String& message, const String& defaultValue, String& result)
  {
    webkitTrace();
    return true;
  }

  void ChromeClientJS::setStatusbarText(const String& string)
  {
    webkitTrace();
  }

  bool ChromeClientJS::shouldInterruptJavaScript()
  {
    webkitTrace();
    return false;
  }

  KeyboardUIMode ChromeClientJS::keyboardUIMode()
  {
    webkitTrace();
    return KeyboardAccessDefault;
  }

  IntRect ChromeClientJS::windowResizerRect() const
  {
    notImplemented();
    return IntRect();
  }

  /*void ChromeClientJS::widgetSizeChanged(const IntSize& oldWidgetSize, IntSize newSize)
  {
    EM_ASM(
           console.log("WebKit: ChromeClientJS::widgetSizeChanged();");
           );
  }

  void ChromeClientJS::performAllPendingScrolls()
  {
    EM_ASM(
           console.log("WebKit: ChromeClientJS::performAllPendingScrolls();");
           );
  }

  void ChromeClientJS::paint(WebCore::Timer<ChromeClient>*)
  {
    EM_ASM(
            console.log("WebKit: ChromeClientJS::paint();");
            );
  }

  void ChromeClientJS::forcePaint()
  {
    EM_ASM(
           console.log("WebKit: ChromeClientJS::forcePaint();");
           );
  }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 // Methods used by HostWindow.
	 virtual bool supportsImmediateInvalidation() { return false; }
	 //virtual void invalidateRootView(const IntRect&, bool immediate) = 0;
	 //virtual void invalidateContentsAndRootView(const IntRect&, bool immediate) = 0;
	 //virtual void invalidateContentsForSlowScroll(const IntRect&, bool immediate) = 0;
	 //virtual void scroll(const IntSize&, const IntRect&, const IntRect&) = 0;
	 #if USE(TILED_BACKING_STORE)
	 //virtual void delegatedScrollRequested(const IntPoint&) = 0;
	 #endif
	 virtual IntPoint screenToRootView(const IntPoint&) const = 0;
	 virtual IntRect rootViewToScreen(const IntRect&) const = 0;
	 virtual PlatformPageClient platformPageClient() const = 0;
	 virtual void scrollbarsModeDidChange() const = 0;
	 #if ENABLE(CURSOR_SUPPORT)
	 virtual void setCursor(const Cursor&) = 0;
	 virtual void setCursorHiddenUntilMouseMoves(bool) = 0;
	 #endif
	 #if ENABLE(REQUEST_ANIMATION_FRAME) && !USE(REQUEST_ANIMATION_FRAME_TIMER)
	 virtual void scheduleAnimation() = 0;
	 #endif

	 */

  void ChromeClientJS::invalidateRootView(const IntRect& updateRect, bool immediate)
  {
    webkitTrace();
		fprintf(stderr,"InvalidateRootView: %i %i %i %i\n", updateRect.x(), updateRect.y(), updateRect.width(), updateRect.height());
  }

  void ChromeClientJS::invalidateContentsAndRootView(const IntRect& updateRect, bool immediate)
  {
    webkitTrace();
		fprintf(stderr,"InvalidateRootView: %i %i %i %i\n", updateRect.x(), updateRect.y(), updateRect.width(), updateRect.height());
  }

  void ChromeClientJS::invalidateContentsForSlowScroll(const IntRect& updateRect, bool immediate)
  {
    webkitTrace();
		fprintf(stderr,"InvalidateRootView: %i %i %i %i\n", updateRect.x(), updateRect.y(), updateRect.width(), updateRect.height());
  }

  void ChromeClientJS::scroll(const IntSize& delta, const IntRect& rectToScroll, const IntRect& clipRect)
  {
    webkitTrace();
  }

  IntRect ChromeClientJS::rootViewToScreen(const IntRect& rect) const
  {
    webkitTrace();
    return rect;
  }

  IntPoint ChromeClientJS::screenToRootView(const IntPoint& point) const
  {
    webkitTrace();
    return point;
  }

  PlatformPageClient ChromeClientJS::platformPageClient() const
  {
    webkitTrace();
    return 0;
  }

  void ChromeClientJS::contentsSizeChanged(Frame* frame, const IntSize& size) const
  {
    webkitTrace();
  }

  void ChromeClientJS::scrollbarsModeDidChange() const
  {
    webkitTrace();
  }

  void ChromeClientJS::mouseDidMoveOverElement(const HitTestResult& hit, unsigned modifierFlags)
  {
    webkitTrace();
  }

  void ChromeClientJS::setToolTip(const String& toolTip, TextDirection)
  {
    webkitTrace();
  }

  void ChromeClientJS::print(Frame* frame)
  {
    webkitTrace();
  }

  void ChromeClientJS::reachedMaxAppCacheSize(int64_t spaceNeeded)
  {
    webkitTrace();
  }

  void ChromeClientJS::reachedApplicationCacheOriginQuota(SecurityOrigin*, int64_t)
  {
    webkitTrace();
  }

  void ChromeClientJS::runOpenPanel(Frame*, PassRefPtr<FileChooser> prpFileChooser)
  {
    webkitTrace();
  }

  void ChromeClientJS::loadIconForFiles(const Vector<WTF::String>& filenames, WebCore::FileIconLoader* loader)
  {
    webkitTrace();
  }

  void ChromeClientJS::setCursor(const Cursor& cursor)
  {
    webkitTrace();
  }

  void ChromeClientJS::setCursorHiddenUntilMouseMoves(bool)
  {
    webkitTrace();
  }

  bool ChromeClientJS::selectItemWritingDirectionIsNatural()
  {
    webkitTrace();
    return false;
  }

  bool ChromeClientJS::selectItemAlignmentFollowsMenuWritingDirection()
  {
    webkitTrace();
    return false;
  }

  bool ChromeClientJS::hasOpenedPopup() const
  {
    webkitTrace();
    return false;
  }

  void ChromeClientJS::attachRootGraphicsLayer(Frame* frame, GraphicsLayer* rootLayer)
  {
    notImplemented();
  }
  
  void ChromeClientJS::setNeedsOneShotDrawingSynchronization()
  {
    notImplemented();
  }
  
  void ChromeClientJS::scheduleCompositingLayerFlush()
  {
    notImplemented();
  }

  PassRefPtr<PopupMenu> ChromeClientJS::createPopupMenu(PopupMenuClient*) const {
    notImplemented();
    return nullptr;
  }

  PassRefPtr<SearchPopupMenu> ChromeClientJS::createSearchPopupMenu(PopupMenuClient*) const {
    notImplemented();
    return nullptr;
  }
  void ChromeClientJS::delegatedScrollRequested(const IntPoint&) {
    notImplemented();
  }
  void ChromeClientJS::formStateDidChange(const WebCore::Node*) {
    notImplemented();
  }
  void ChromeClientJS::numWheelEventHandlersChanged(unsigned) {
    notImplemented();
  }
  void ChromeClientJS::scheduleAnimation() {
    notImplemented();
  }

  /*void ChromeClientJS::dispatchViewportPropertiesDidChange(const ViewportArguments& arguments) const
	 {
	 EM_ASM(
	 console.log("WebKit: ChromeClientJS::dispatchViewportPropertiesDidChange();");
	 );
	 }*/

  /*PassRefPtr<WebCore::PopupMenu> ChromeClientJS::createPopupMenu(WebCore::PopupMenuClient* client) const
	 {
	 EM_ASM(
	 console.log("createPopupMenu();");
	 );
	 }*/

  /*PassRefPtr<WebCore::SearchPopupMenu> ChromeClientJS::createSearchPopupMenu(WebCore::PopupMenuClient* client) const
	 {
	 EM_ASM(
	 console.log("WebKit: ChromeClientJS::createSearchPopupMenu();");
	 );
	 }*/

  /*IntRect ChromeClientJS::windowResizerRect() const
  {
    return IntRect();
  }
  PlatformPageClient ChromeClientJS::platformPageClient() const
  {
    EM_ASM(
           console.log("WebKit: ChromeClientJS::scrollbarsModeDidChange();");
           );
    return NULL;
  }
  void ChromeClientJS::scrollbarsModeDidChange() const
  {
    EM_ASM(
           console.log("WebKit: ChromeClientJS::scrollbarsModeDidChange();");
           );
  }
*/
  /*ChromeClientJS::CompositingTriggerFlags ChromeClientJS::allowedCompositingTriggers() const
  {
    EM_ASM(
           console.log("WebKit: ChromeClientJS::allowCompositingTriggers();");
           );
    return false;
  }*/
}